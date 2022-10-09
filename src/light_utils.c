/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dirony <dirony@21-school.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:30:18 by dirony            #+#    #+#             */
/*   Updated: 2022/10/09 17:48:06 by dirony           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"


float	ft_diff_lght(t_vec3 nrmlz, t_vec3 inter_point, t_main *data)
{
	t_vec3	spot;
	t_vec3	tmp;
	float	res;

	tmp = ft_sub(&(data->scene.lght.pos), &inter_point);
	spot = ft_norm(&tmp);
	res = ft_dot(&nrmlz, &spot);
	return (res * data->scene.lght.bright);
}

float	ft_spec_lght(t_vec3	nrmlz, t_vec3 direction, t_vec3 inter_point, \
																t_main *data)
{
	float	bright;
	t_vec3	reflect;
	t_vec3	spot;
	t_vec3	tmp;

	bright = data->scene.lght.bright;
	tmp = ft_sub(&(data->scene.lght.pos), &inter_point);
	spot = ft_norm(&tmp);
	reflect = ft_reflect(&direction, &nrmlz);
	return (pow(fmax(ft_dot(&reflect, &spot), 0), 32) * bright);
}

int	ft_drop_shadow(t_scene *scene, t_figure *figure, t_vec3 *inter_point)
{
	t_vec3		dir;
	t_vec3		vec_tmp;
	t_figure	*iter;
	float		dist;

	vec_tmp = vector_minus(scene->light->origin, *inter_point);
	dir = get_norm_vector(&vec_tmp);
	iter = scene->figures;
	while (iter)
	{
		dist = ft_find_dist(iter, inter_point, &dir);
		if (iter->type != figure->type)
		{
			if (dist > 0 && dist < ft_dist(*inter_point, scene->light->origin) \
			&& iter != figure)
				return (1);
		}
		iter = iter->next;
	}
	return (0);
}

t_vec3	ft_normal_surface(t_vec3 inter_point, t_figure *figure)
{
	t_vec3	normale;

	if (figure->type == SPHERE)
	{
		normale = vector_minus(inter_point, figure->center);
		vector_normalize(&normale);
	}
	// else if (sh->type == PLANE)
	// 	nrmlz = ft_norm(&(sh->direction));
	// else if (sh->type == CYLINDER)
	// 	nrmlz = ft_cylinder_norm(sh, &inter_point);
	return (normale);
}

int	ft_lighting(t_scene *scene, t_figure *figure, t_vec3 *ray, float dist)
{
	t_vec3	inter_point;
	t_vec3	nrmlz;
	t_vec3	tmp;
	int		drop;
	int		clr;

	tmp = vec3_multiply(*ray, dist);
	inter_point = vector_sum(scene->camera->orientation, tmp);
	nrmlz = ft_normal_surface(inter_point, figure);
	drop = ft_drop_shadow(scene, figure, &inter_point);
	if (drop == 0)
		clr = ft_add_clr3(ft_mul_clr(figure->color, data->scene.amb.bright), \
		ft_mul_clr(figure->color, ft_diff_lght(nrmlz, inter_point, data) * DIFF), \
ft_mul_clr(figure->color, ft_spec_lght(nrmlz, *ray, inter_point, data) * SPEC));
	else if (drop == 1)
		clr = ft_add_clr(ft_add_clr3 \
		(ft_mul_clr(figure->color, data->scene.amb.bright), \
ft_mul_clr(figure->color, ft_diff_lght(nrmlz, inter_point, data) * DIFF), 0), SHADOW);
	return (clr);
}
