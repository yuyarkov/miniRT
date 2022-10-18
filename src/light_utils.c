/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dirony <dirony@21-school.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:30:18 by dirony            #+#    #+#             */
/*   Updated: 2022/10/18 20:42:16 by dirony           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

float	light_angle(t_vec3 normale, t_vec3 point, t_scene *scene)
{
	t_vec3	temp;
	float	result;

	temp = vector_sub(scene->light->origin, point);
	vector_normalize(&temp);
	result = scalar_product(normale, temp);
	return (result * scene->light->power);
}

float	special_light(t_vec3 normale, t_vec3 ray, t_vec3 point, \
																t_scene *scene)
{
	float	power;
	t_vec3	reflect;
	t_vec3	temp;

	power = scene->light->power;
	temp = vector_sub(scene->light->origin, point);
	vector_normalize(&temp);
	reflect = reflect_vector(ray, normale);
	return (pow(fmax(scalar_product(reflect, temp), 0), 32) * power);
}

int	is_in_shadow(t_scene *scene, t_figure *figure, t_vec3 *point)
{
	t_vec3		dir;
	t_vec3		vec_temp;
	t_figure	*iter;
	float		dist;

	vec_temp = vector_sub(scene->light->origin, *point);
	dir = get_norm_vector(&vec_temp);
	iter = scene->figures;
	while (iter)
	{
		dist = find_distance(iter, point, &dir);
		if (iter->type != figure->type)
		{
			if (dist > 0 && \
				dist < get_distance(*point, scene->light->origin) && \
				iter != figure)
				return (1);
		}
		iter = iter->next;
	}
	return (0);
}

t_vec3	get_normale(t_vec3 point, t_figure *figure)
{
	t_vec3	normale;

	if (figure->type == SPHERE)
	{
		normale = vector_sub(point, figure->center);
		vector_normalize(&normale);
	}
	else if (figure->type == PLANE)
		normale = get_norm_vector(&(figure->norm_vector));
	else if (figure->type == CYLINDER)
		normale = ft_cylinder_norm(figure, &point);
	return (normale);
}

int	lightning(t_scene *scene, t_figure *fig, t_vec3 *ray, float dist)
{
	t_vec3	point;
	t_vec3	normale;
	t_vec3	temp;
	int		shadow;
	int		res;

	temp = vector_multiply(*ray, dist);
	point = vector_sum(scene->camera->position, temp);
	normale = get_normale(point, fig);
	shadow = is_in_shadow(scene, fig, &point);
	res = BLACK;
	if (shadow)
		res = add_color(add_3_colors(change_bright(fig->color, \
		scene->ambient->power), change_bright(fig->color, \
		light_angle(normale, point, scene) * DIFF), 0), SHADOW);
	else
		res = add_3_colors(change_bright(fig->color, scene->ambient->power), \
		change_bright(fig->color, light_angle(normale, point, scene) \
		* DIFF), change_bright(fig->color, \
		special_light(normale, *ray, point, scene) * SPEC));
	return (res);
}
