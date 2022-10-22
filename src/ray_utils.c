/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dirony <dirony@21-school.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 19:04:20 by dirony            #+#    #+#             */
/*   Updated: 2022/10/22 18:57:58 by dirony           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

t_vec3	ray_by_x_y(int x, int y, t_scene *scene)
{
	float	ray_x;
	float	ray_y;
	t_vec3	result;

	ray_x = - (WIN_WIDTH / 2) + x;
	ray_y = - (WIN_HEIGHT / 2) + y;
	result = build_vector(ray_x, ray_y, scene->camera->f);
	vector_normalize(&result);
	return (result);
}
