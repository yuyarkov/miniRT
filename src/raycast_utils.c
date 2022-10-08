/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dirony <dirony@21-school.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 17:05:49 by dirony            #+#    #+#             */
/*   Updated: 2022/10/08 20:06:00 by dirony           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

static int	return_ambient(t_scene *scene)
{
	t_color_r	col_tmp;
	t_color_r	val;

	col_tmp = from_color_to_r(scene->ambient->color);
	val = color_r_mix(from_int_to_r(COLOR_BACKGROUND), col_tmp, 0.5);
	val = color_r_multiply_val(val, scene->ambient->intensity * 2);
	return (color_r_to_int(val));
}

static t_ray	get_refract_ray(t_ray *ray, t_hit *hit_info)
{
	t_ray		refract_ray;

	refract_ray.direction = ray_refract(ray->direction, hit_info->hit_normal,
			hit_info->hit_figure->albedo[5], 1.0);
	if (vector_scalar_product(refract_ray.direction, hit_info->hit_normal) < 0)
		refract_ray.origin = (vector_minus(hit_info->hit,
					vector_multiply(hit_info->hit_normal, 1e-3)));
	else
		refract_ray.origin = (vector_sum(hit_info->hit,
					vector_multiply(hit_info->hit_normal, 1e-3)));
	return (refract_ray);
}

static t_ray	get_reflect_ray(t_ray *ray, t_hit *hit_info)
{
	t_ray		reflect_ray;

	reflect_ray.direction = ray_reflect(ray->direction, hit_info->hit_normal);
	if (vector_scalar_product(reflect_ray.direction, hit_info->hit_normal) < 0)
		reflect_ray.origin = (vector_minus(hit_info->hit,
					vector_multiply(hit_info->hit_normal, 1e-3)));
	else
		reflect_ray.origin = (vector_sum(hit_info->hit,
					vector_multiply(hit_info->hit_normal, 1e-3)));
	return (reflect_ray);
}

int	ray_cast(t_ray *ray, t_scene *scene, int bounce)
{
	t_color_r	material;
	t_hit		hit_info;
	t_ray		bounce_ray;

	hit_info.hit_ray = *ray;
	if (bounce > 2)
		return (return_ambient(scene));
	scene_intersect(scene->figures, &hit_info);
	if (!hit_info.hit_figure)
		return (return_ambient(scene));
	hit_info.hit_normal = get_figure_normal(hit_info.hit,
			hit_info.hit_figure, &hit_info);
	bounce_ray = get_reflect_ray(ray, &hit_info);
	hit_info.reflect_color = ray_cast(&bounce_ray, scene, bounce + 1);
	bounce_ray = get_refract_ray(ray, &hit_info);
	hit_info.refract_color = ray_cast(&bounce_ray, scene, bounce + 1);
	//get_pixel_color(scene, &hit_info, &material, ft_lstsize(*(scene->lights)));
	return (color_r_to_int(material));
}