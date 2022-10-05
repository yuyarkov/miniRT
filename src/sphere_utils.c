/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dirony <dirony@21-school.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 18:42:24 by dirony            #+#    #+#             */
/*   Updated: 2022/10/05 20:52:21 by dirony           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

int	get_darker_color_from_radius(float h, int c)
{
	return (create_argb_color(h, get_r_color(c), get_g_color(c), get_b_color(c)));
}

// int sphere_intersect(t_vec3 ray, t_vec3 center, float radius, int color)
// {
// 	float dist_to_sphere;
// 	float h;
	
// 	//print_vector(ray, "ray: ");
	
// 	dist_to_sphere = vector_scalar_product(ray, center);
// 	vector_stretch(&ray, dist_to_sphere); //переделать под временный луч, иначе этот луч не получится использовать дальше. Или может получится, нормализовать его снова и т.д.
// 	h = vector_len(vector_minus(ray, center));
//     if (h < (radius * 0.999))
// 		return get_darker_color_from_radius(h / radius * 256, color); // есть пересечение, верну цвет для эксперимента
// 	else
// 		return 0;
// }


float	abs_value(float x)
{
	if (x >= 0)
		return (x);
	else
		return (-x);
}

int	build_color(int lightness, int c)
{
	unsigned int	result;

	//printf("inside build_color, original_lightness: %d, r: %d, g: %d, b: %d\n", get_a_color(c), get_r_color(c), get_g_color(c), get_b_color(c));
	result = create_argb_color(lightness, get_r_color(c), get_g_color(c), get_b_color(c));
	//printf("inside build_color, result: %u, lightness: %d, r: %d, g: %d, b: %d\n", result, get_a_color(result), get_r_color(result), get_g_color(result), get_b_color(result));
	return (result);
}

float	get_reflection_angle(t_vec3 ray, float h, float dist_to_sphere, t_figure *sphere, t_light *light)
{
	float	cut_extra_from_ray;
//	float	angle_of_ray;
	float	angle_of_light;
	int		result;
	t_vec3	normal_in_closest_intersection;
	t_vec3	ray_from_sphere_to_light;

	if (h >= sphere->radius / 2)
		return (255);
	cut_extra_from_ray = sqrt(sphere->radius * sphere->radius / 4 - h * h);
	vector_normalize(&ray);
	vector_stretch(&ray, dist_to_sphere - cut_extra_from_ray);//теперь ray указывает в точку ближайшего пересечения со сферой

	ray_from_sphere_to_light = vector_minus(light->origin, ray);
	normal_in_closest_intersection = vector_minus(ray, sphere->center);//точно ли нормаль смотрит из центра сферы в точку пересечения?
	vector_normalize(&normal_in_closest_intersection);
	vector_normalize(&ray);

	vector_normalize(&ray_from_sphere_to_light);

	angle_of_light = vector_scalar_product(ray_from_sphere_to_light, normal_in_closest_intersection);

	if (angle_of_light > 0)
	{
		result = (int) (255 - (angle_of_light * 255 * light->intensity)); //умножаю на 255, чтобы привести к шкале интенсивности цвета в компоненте а
		if (result == 0)
			result = 0.01;
	}
	else
		result = 255;
//printf("angle of ray: %f, angle of light: %f, result: %d\n", angle_of_ray, angle_of_light, result);
return (result);
}


int sphere_intersect(t_vec3 ray_original, t_scene *scene)
{
	t_figure	*sphere;
	float	dist_to_sphere;
	float	h;
	float	lightness;
	int		result_color;
	t_vec3	ray;
	
	result_color = BLACK;
	sphere = scene->figures;
	while (sphere && sphere->type == SPHERE)
	{
		ray = ray_original;
		dist_to_sphere = vector_scalar_product(ray, sphere->center);
		vector_stretch(&ray, dist_to_sphere);
		h = vector_len(vector_minus(ray, sphere->center));
    	if (h < sphere->radius * 2)
		{
			if (h < sphere->radius)
				lightness = get_reflection_angle(ray, h, dist_to_sphere, sphere, scene->light);
			else
				lightness = 255;
			result_color = build_color(lightness, sphere->colour); // есть пересечение, верну цвет для эксперимента
		}
//		printf("inside sphere_intersect, sphere: %p\n", sphere);
		sphere = sphere->next;
		//sphere = NULL;
	}
	return (result_color);
}