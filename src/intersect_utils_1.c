/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dirony <dirony@21-school.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 15:38:09 by dirony            #+#    #+#             */
/*   Updated: 2022/10/18 21:08:37 by dirony           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

float	plane_intersect(t_figure *plane, t_vec3 *cam_origin, \
															t_vec3 *direction)
{
	float	t;
	t_vec3	subtraction;
	float	dot_product_1;
	float	dot_product_2;

	subtraction = vector_sub(*cam_origin, plane->center);
	dot_product_1 = scalar_product(subtraction, plane->norm_vector);
	dot_product_2 = scalar_product(*direction, plane->norm_vector);
	t = -dot_product_1 / dot_product_2;
	return (t);
}

float	sphere_intersect(t_figure *sphere, t_vec3 *cam_origin, \
											t_vec3 *direction, t_discrmn box)
{
	float	dist_1;
	float	dist_2;
	float	min;
	float	max;
	t_vec3	cam_sphere;

	cam_sphere = vector_sub(*cam_origin, sphere->center);
	box.b = 2 * (scalar_product(cam_sphere, *direction));
	box.c = scalar_product(cam_sphere, cam_sphere) - powf(sphere->radius, 2);
	box.discr = (box.b * box.b) - (4 * box.c);
	if (box.discr < 0)
		return (0);
	dist_1 = ((box.b * (-1)) - sqrt(box.discr)) / 2;
	dist_2 = ((box.b * (-1)) + sqrt(box.discr)) / 2;
	min = fminf(dist_1, dist_2);
	max = fmaxf(dist_1, dist_2);
	if (min >= 0)
		box.res = min;
	else
		box.res = max;
	return (box.res);
}

float	find_distance(t_figure *figure, t_vec3 *cam_origin, t_vec3 *ray)
{
	float		distance;
	t_discrmn	box;

	box = (t_discrmn){};
	distance = 0;
	if (figure->type == SPHERE)
		distance = sphere_intersect(figure, cam_origin, ray, box);
	else if (figure->type == PLANE)
		distance = plane_intersect(figure, cam_origin, ray);
	else if (figure->type == CYLINDER)
		distance = cylinder_intersect(figure, cam_origin, ray, box);
	return (distance);
}

int	get_pixel_color(t_scene *scene, t_vec3 *ray)
{
	float		dist;
	float		dist_min;
	int			color;
	t_figure	*iter;
	t_figure	*result;

	result = NULL;
	dist_min = MAXFLOAT;
	color = BLACK;
	iter = scene->figures;
	while (iter)
	{
		dist = find_distance(iter, &(scene->camera->position), ray);
		if (dist > 0 && dist < dist_min)
		{
			dist_min = dist;
			result = iter;
		}
		iter = iter->next;
	}
	if (result != NULL)
		color = lightning(scene, result, ray, dist_min);
	return (color);
}
