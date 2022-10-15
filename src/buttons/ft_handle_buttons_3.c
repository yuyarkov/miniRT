/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_buttons_3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 21:35:31 by merlich           #+#    #+#             */
/*   Updated: 2022/10/15 19:24:04 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	ft_move_camera(int keycode, float step, t_data *pic)
{
	t_camera	*camera;

	camera = pic->scene_ptr->camera;
	if (keycode == UP)
		camera->position.y -= step;
	else if (keycode == DOWN)
		camera->position.y += step;
	else if (keycode == LEFT)
		camera->position.x -= step;
	else if (keycode == RIGHT)
		camera->position.x += step;
	else if (keycode == FORWARD)
		camera->position.z += step;
	else if (keycode == BACKWARD)
		camera->position.z -= step;
}

void	ft_rotate_camera(int keycode, float angle, t_data *pic)
{
	if (keycode == ROT_FRONT)
		pic->scene_ptr->camera->angle_z += angle;
	else if (keycode == ROT_BACK)
		pic->scene_ptr->camera->angle_z -= angle;
	else if (keycode == ROT_LEFT)
		pic->scene_ptr->camera->angle_y -= angle;
	else if (keycode == ROT_RIGHT)
		pic->scene_ptr->camera->angle_y += angle;
	else if (keycode == ROT_UP)
		pic->scene_ptr->camera->angle_x += angle;
	else if (keycode == ROT_DOWN)
		pic->scene_ptr->camera->angle_x -= angle;
}

void	ft_change_fov(int keycode, int step, t_data *pic)
{
	if (keycode == FOV_PLUS)
	{
		pic->scene_ptr->camera->fov += step;
		if (pic->scene_ptr->camera->fov >= 170)
			pic->scene_ptr->camera->fov = 170;
	}
	else if (keycode == FOV_MINUS)
	{
		pic->scene_ptr->camera->fov -= step;
		if (pic->scene_ptr->camera->fov <= 10)
			pic->scene_ptr->camera->fov = 10;
	}
}
