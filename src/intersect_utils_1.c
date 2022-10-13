/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dirony <dirony@21-school.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 15:38:09 by dirony            #+#    #+#             */
/*   Updated: 2022/10/13 21:40:51 by dirony           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

float	ft_plane_intersect(t_figure *plane, t_vec3 *cam_origin, \
															t_vec3 *direction)
{
	float	t;
	t_vec3	subtraction;
	float	dot_product_1;
	float	dot_product_2;

	subtraction = vector_minus(*cam_origin, plane->center);
	dot_product_1 = vector_scalar_product(subtraction, plane->norm_vector);
	dot_product_2 = vector_scalar_product(*direction, plane->norm_vector);
	t = -dot_product_1 / dot_product_2;
	return (t);
}

float	ft_sphere_intersect(t_figure *sphere, t_vec3 *cam_origin, \
											t_vec3 *direction, t_discrmn box)
{
	float	dist_1;
	float	dist_2;
	float	min;
	float	max;
	t_vec3	cam_sphere;

	cam_sphere = vector_minus(*cam_origin, sphere->center);
	box.b = 2 * (vector_scalar_product(cam_sphere, *direction));
	box.c = vector_scalar_product(cam_sphere, cam_sphere) - (sphere->radius * sphere->radius);
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
	// if (box.res > 0)
	// 	printf("inside sphere_intersect, box.res: %f\n", box.res);
	return (box.res);
}

float	find_distance(t_figure *figure, t_vec3 *cam_origin, t_vec3 *ray)
{
	float		distance;
	t_discrmn	box;

	box = (t_discrmn){};
	distance = 0;
	if (figure->type == SPHERE)
		distance = ft_sphere_intersect(figure, cam_origin, ray, box);
	else if (figure->type == PLANE)
		distance = ft_plane_intersect(figure, cam_origin, ray);
	else if (figure->type == CYLINDER)
		distance = ft_cylinder_intersect(figure, cam_origin, ray, box);
	return (distance);
}

int	ft_intersection(t_scene *scene, t_vec3 *ray)
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
	// if (dist_min != MAXFLOAT)
	// 	printf("inside intersection, dist_min: %f\n", dist_min);
	if (result != NULL)
		color = ft_lighting(scene, result, ray, dist_min);//сцена, в какую фигуру попали, луч, дистанция до первой фигуры
	return (color);
}
