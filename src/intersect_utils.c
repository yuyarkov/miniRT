/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dirony <dirony@21-school.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 16:33:08 by dirony            #+#    #+#             */
/*   Updated: 2022/10/08 19:42:56 by dirony           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

int	intersect_figure(t_ray *ray, t_figure *figure, double *t)
{
	if (figure->type == SPHERE)
		return (sphere_intersect(*ray, *(t_sphere *)figure, t));
	// else if (figure->type == PLANE)
	// 	return (plane_intersect(*ray, *(t_plane *)figure->pointer, t));
	// else if (figure->type == CYLINDER)
	// 	return (cylinder_intersect(*ray, *(t_cylinder *)figure->pointer, t));
	// else if (figure->type == CONE)
	// 	return (cone_intersect(*ray, *(t_cone *)figure->pointer, t));
	else
		return (0);
}

t_vec3	get_figure_normal(t_vec3 hit, t_figure *figure, t_hit *info)
{
	t_vec3	norm;

	(void) info;
	norm = vector_create(0, 0, 0);
	if (figure->type == CYLINDER)
	{
		// norm = get_cylinder_normal(hit, *(t_cylinder *)figure->pointer);
		// if (vector_dot_product(info->hit_ray.direction, norm) > 0)
		// 	norm = vector_multiply(norm, -1.0);
	}
	// else if (figure->type == CONE)
	// {
	// 	norm = get_cone_normal(hit, *(t_cone *)figure->pointer);
	// 	if (vector_dot_product(info->hit_ray.direction, norm) > 0)
	// 		norm = vector_multiply(norm, -1.0);
	// }
	else if (figure->type == SPHERE)
		norm = sphere_get_normal(hit, *(t_sphere *)figure);
	// if (figure->type == PLANE)
	// {
	// 	norm = get_plane_normal(hit, *(t_plane *)figure->pointer);
	// 	if (vector_dot_product(info->hit_ray.direction, norm) > 0)
	// 		norm = vector_multiply(norm, -1.0);
	// }
	return (norm);
}

int	scene_intersect(t_figure *figures, t_hit *info)
{
	t_figure	*tmp;
	double		dist_i;
	double		figure_dist;

	figure_dist = DBL_MAX;
	tmp = figures;
	while (tmp)
	{
		dist_i = 0;
		if (intersect_figure(&info->hit_ray, tmp,
			&dist_i) && dist_i < figure_dist)
		{
			figure_dist = dist_i;
			info->hit = vector_sum(info->hit_ray.origin,
					vector_multiply(info->hit_ray.direction, dist_i));
			info->hit_figure = tmp;
		}
		tmp = tmp->next;
	}
	return (figure_dist < 1000);
}

int	is_in_shadow(t_figure *figures, t_light *light, t_hit *info)
{
	t_vec3	shadow_orig;
	t_vec3	light_dir;
	float	light_distance;
	t_hit	shadow_hit;

	light_dir = vector_minus(light->origin, info->hit);
	vector_normalize(&light_dir);
	light_distance = vector_len(vector_minus(light->origin, info->hit));
	if (vector_scalar_product(light_dir, info->hit_normal) < 0) //dot product?
		shadow_orig = (vector_minus(info->hit,
					vector_multiply(info->hit_normal, 1e-3)));
	else
		shadow_orig = (vector_sum(info->hit,
					vector_multiply(info->hit_normal, 1e-3)));
	shadow_hit.hit_ray = ray_create(shadow_orig, light_dir);
	if (scene_intersect(figures, &shadow_hit)
		&& vector_len(vector_minus(shadow_hit.hit,
				shadow_orig)) < light_distance)
		return (1);
	return (0);
}
