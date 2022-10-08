/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_buttons_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 20:22:22 by merlich           #+#    #+#             */
/*   Updated: 2022/10/08 18:26:33 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	ft_redraw_image(t_data *pic)
{
	mlx_destroy_image(pic->mlx, pic->img);
	pic->img = mlx_new_image(pic->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	pic->addr = mlx_get_data_addr(pic->img, &pic->bits_per_p,
			&pic->line_len, &pic->endian);
	render(pic, pic->scene_ptr);
	mlx_put_image_to_window(pic->mlx, pic->window, pic->img, M_LEFT, M_TOP);
}

int ft_just_exit(t_data *pic)
{
	mlx_destroy_image(pic->mlx, pic->img);
	mlx_destroy_window(pic->addr, pic->window);
	exit(EXIT_SUCCESS);
	return (0);
}

void	ft_move_camera(int keycode, float step, t_data *pic)
{
	t_camera	*camera;

	camera = pic->scene_ptr->camera;

	if (keycode == UP)
		camera->position.y += step;
	else if (keycode == DOWN)
		camera->position.y -= step;
	else if (keycode == LEFT)
		camera->position.z -= step;
	else if (keycode == RIGHT)
		camera->position.z += step;
	printf("CAM.X = %f\n", pic->scene_ptr->camera->position.x);
	printf("CAM.Y = %f\n", pic->scene_ptr->camera->position.y);
	printf("CAM.Z = %f\n", pic->scene_ptr->camera->position.z);
}

void	ft_rotate_camera(int keycode, float angle, t_data *pic)
{
	if (keycode == ROT_UP)
		pic->scene_ptr->camera->angle_y += angle;
	else if (keycode == ROT_DOWN)
		pic->scene_ptr->camera->angle_y -= angle;
	else if (keycode == ROT_LEFT)
		pic->scene_ptr->camera->angle_z -= angle;
	else if (keycode == ROT_RIGHT)
		pic->scene_ptr->camera->angle_z += angle;
}

int ft_handle_buttons(int keycode, t_data *pic)
{
	printf("%d\n", keycode);
	if (keycode == ESC)
		ft_just_exit(pic);
	else if (keycode == MINUS)
		ft_resize_figure(-SIZE_STEP, pic);
	else if (keycode == PLUS)
		ft_resize_figure(SIZE_STEP, pic);
	else if (keycode == F || keycode == H || keycode == T || keycode == G || \
			keycode == R || keycode == Y)
		ft_rotate_figure(keycode, ROT_ANGLE, pic);
	else if (keycode == FOV_PLUS || keycode == FOV_MINUS)
		ft_change_fov(keycode, CAM_STEP, pic);
	else if (keycode == W || keycode == A || keycode == S || keycode == D || \
			keycode == SHIFT || keycode == X || keycode == SPACE || \
			keycode == Z)
		ft_move_figure(keycode, MOVE_STEP, pic);
	else if (keycode == UP || keycode == DOWN || keycode == LEFT || \
			keycode == RIGHT)
		ft_move_camera(keycode, MOVE_STEP, pic);
	else if (keycode == UP || keycode == DOWN || keycode == LEFT || \
			keycode == RIGHT)
		ft_rotate_camera(keycode, ROT_ANGLE, pic);
	// printf("CAM.X = %f\n", pic->scene_ptr->camera->position.x);
	ft_redraw_image(pic);
	return (0);
}
