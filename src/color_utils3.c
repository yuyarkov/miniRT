/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dirony <dirony@21-school.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 19:48:09 by dirony            #+#    #+#             */
/*   Updated: 2022/10/08 20:03:52 by dirony           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

static void	light_color_add(t_light *light, t_hit *hit_info,
	float ds_light[2], t_color_r ds_color[2])
{
	t_vec3	light_dir;
	double	fac;

	light_dir = vector_minus(light->origin, hit_info->hit);
	vector_normalize(&light_dir);
	fac = vector_scalar_product(light_dir, hit_info->hit_normal);
	ds_light[0] += light->intensity * fmax(0.0, fac);
	ds_light[1] += powf(fmax(0.0, vector_scalar_product(
					ray_reflect(light_dir, hit_info->hit_normal),
					hit_info->hit_ray.direction)),
			(hit_info->hit_figure->albedo[4]) / light->intensity);
	if (fac > 0)
	{
		fac *= light->intensity;
		fac /= sqrt(vector_dist(light->origin, hit_info->hit)) / 2;
		ds_color[0] = color_r_add(ds_color[0],
				color_r_multiply_val(light->color_r, fmin(fac, 1.)));
	}
}

void	iterate_all_lights(t_scene *scene, t_hit *hit_info,
	float ds_light[2], t_color_r ds_color[2])
{
	t_light	*tmp;

	tmp = scene->light;
	while (tmp)
	{
		ds_color[1] = color_r_add(ds_color[1],
				tmp->color_r);
		if (is_in_shadow(scene->figures,
				tmp, hit_info))
		{
			tmp = tmp->next;
			continue ;
		}
		light_color_add(tmp,
			hit_info, ds_light, ds_color);
		tmp = tmp->next;
	}
}

static void	apply_ambient(t_color_r *material, t_scene *scene)
{
	t_color_r	col_tmp;

	col_tmp = from_color_to_r(scene->ambient->color);
	*material = color_r_mix(*material, col_tmp, 0.5);
	*material = color_r_multiply_val(*material, scene->ambient->intensity * 2);
}

t_color_r	scale_col(t_color_r c)
{
	float		max;
	float		scale;
	t_color_r	result;

	max = fmax(c.r, fmax(c.g, c.b));
	scale = 1.0 / max;
	result.r = c.r * scale;
	result.g = c.g * scale;
	result.b = c.b * scale;
	return (result);
}

void	get_pixel_color(t_scene *scene, t_hit *hit_info,
			t_color_r *material, int lights_num)
{
	float		ds_light[2];
	t_color_r	ds_color[2];
	t_color_r	col_tmp;

	ft_memset(ds_light, 0, sizeof(ds_light));
	ft_memset(ds_color, 0, sizeof(ds_color));
	iterate_all_lights(scene, hit_info, ds_light, ds_color);
	*material = from_color_to_r(hit_info->hit_figure->color);
	// if (hit_info->hit_figure->checkerb)
	// 	*material = checkerboard2(hit_info);
	*material = color_r_multiply_val(*material, ds_light[0] / lights_num);
	*material = color_r_multiply_val(*material, hit_info->hit_figure->albedo[0]);
	col_tmp = color_r_add(scale_col(ds_color[0]), *material);
	col_tmp = color_r_multiply_val(col_tmp, ds_light[1]);
	col_tmp = color_r_multiply_val(col_tmp, hit_info->hit_figure->albedo[1]);
	*material = color_r_add(*material, col_tmp);
	col_tmp = color_r_multiply_val(from_int_to_r(hit_info->reflect_color),
			hit_info->hit_figure->albedo[2]);
	*material = color_r_add(*material, col_tmp);
	col_tmp = color_r_multiply_val(from_int_to_r(hit_info->refract_color),
			hit_info->hit_figure->albedo[3]);
	*material = color_r_add(*material, col_tmp);
	*material = color_r_mix(*material, ds_color[0], 0.5);
	apply_ambient(material, scene);
}
