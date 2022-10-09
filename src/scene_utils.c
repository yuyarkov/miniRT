/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 19:04:08 by dirony            #+#    #+#             */
/*   Updated: 2022/10/09 20:48:14 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

float	get_focus_distance(t_scene *scene)
{
	float	result;
	float	half_fov;

	half_fov = scene->camera->fov / 2 * M_PI / 180;
	result = (float)(WINDOW_WIDTH / 2 / tan(half_fov));
	return (result);
}
