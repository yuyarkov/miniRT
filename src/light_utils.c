/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:30:18 by dirony            #+#    #+#             */
/*   Updated: 2022/10/15 19:56:23 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

float	ft_diff_light(t_vec3 normale, t_vec3 inter_point, t_scene *scene)
{
	t_vec3	spot;
	t_vec3	tmp;
	float	res;

	tmp = vector_sub(scene->light->origin, inter_point);
	spot = get_norm_vector(&tmp);
	res = vector_s_prod(normale, spot);
	return (res * scene->light->power);
}

float	ft_spec_light(t_vec3 normale, t_vec3 ray, t_vec3 inter_point, \
																t_scene *scene)
{
	float	power;
	t_vec3	reflect;
	t_vec3	spot;
	t_vec3	tmp;

	power = scene->light->power;
	tmp = vector_sub(scene->light->origin, inter_point);
	spot = get_norm_vector(&tmp);
	reflect = ft_reflect_vector(ray, normale);
	return (pow(fmax(vector_s_prod(reflect, spot), 0), 32) * power);
}

int	ft_drop_shadow(t_scene *scene, t_figure *figure, t_vec3 *inter_point)
{
	t_vec3		dir;
	t_vec3		vec_tmp;
	t_figure	*iter;
	float		dist;

	vec_tmp = vector_sub(scene->light->origin, *inter_point);
	dir = get_norm_vector(&vec_tmp);
	iter = scene->figures;
	while (iter)
	{
		dist = find_distance(iter, inter_point, &dir);
		if (iter->type != figure->type)
		{
			if (dist > 0 && \
				dist < ft_find_dist(*inter_point, scene->light->origin) && \
				iter != figure)
				return (1);
		}
		iter = iter->next;
	}
	return (0);
}

t_vec3	ft_normale_surface(t_vec3 inter_point, t_figure *figure)
{
	t_vec3	normale;

	if (figure->type == SPHERE)
	{
		normale = vector_sub(inter_point, figure->center);
		vector_normalize(&normale);
	}
	else if (figure->type == PLANE)
		normale = get_norm_vector(&(figure->norm_vector));
	else if (figure->type == CYLINDER)
		normale = ft_cylinder_norm(figure, &inter_point);
	return (normale);
}

int	ft_lighting(t_scene *scene, t_figure *figure, t_vec3 *ray, float dist)
{
	t_vec3	inter_point;
	t_vec3	normale;
	t_vec3	tmp;
	int		drop;
	int		res;

	tmp = vector_multiply(*ray, dist);
	inter_point = vector_sum(scene->camera->position, tmp);
	normale = ft_normale_surface(inter_point, figure);
	drop = ft_drop_shadow(scene, figure, &inter_point);
	res = BLACK;
	if (drop == 0)
	{
		res = ft_add_clr3(ft_mul_clr(figure->color, scene->ambient->power), \
		ft_mul_clr(figure->color, ft_diff_light(normale, inter_point, scene) \
		* DIFF), ft_mul_clr(figure->color, \
		ft_spec_light(normale, *ray, inter_point, scene) * SPEC));
	}
	else if (drop == 1)
	{
		res = ft_add_clr(ft_add_clr3(ft_mul_clr(figure->color, \
		scene->ambient->power), ft_mul_clr(figure->color, \
		ft_diff_light(normale, inter_point, scene) * DIFF), 0), SHADOW);
	}
	return (res);
}
