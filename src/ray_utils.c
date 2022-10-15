/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 19:04:20 by dirony            #+#    #+#             */
/*   Updated: 2022/10/15 18:09:12 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

t_ray	ray_create(t_vec3 origin, t_vec3 direction)
{
	t_ray	result;

	result.origin = origin;
	result.direction = direction;
	return (result);
}

t_vec3	ray_by_x_y(int x, int y, t_scene *scene)
{
	float	ray_x;
	float	ray_y;
	t_vec3	result;

	ray_x = - (WIN_WIDTH / 2) + x;
	ray_y = - (WIN_HEIGHT / 2) + y;
	result = ft_build_vector(ray_x, ray_y, scene->camera->f);
	vector_normalize(&result);
	return (result);
}
