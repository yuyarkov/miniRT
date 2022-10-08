/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_buttons_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 20:22:22 by merlich           #+#    #+#             */
/*   Updated: 2022/10/08 22:08:31 by merlich          ###   ########.fr       */
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
			keycode == Z || keycode == Q || keycode == E)
		ft_move_figure(keycode, MOVE_STEP, pic);
	else if (keycode == UP || keycode == DOWN || keycode == LEFT || \
			keycode == RIGHT || keycode == FORWARD || keycode == BACKWARD)
		ft_move_camera(keycode, MOVE_STEP, pic);
	else if (keycode == ROT_UP || keycode == ROT_DOWN || keycode == ROT_LEFT \
			|| keycode == ROT_RIGHT || keycode == ROT_FRONT || keycode == ROT_BACK)
		ft_rotate_camera(keycode, ROT_ANGLE, pic);
	else if (keycode == I || keycode == K || keycode == J || \
			keycode == L || keycode == U || keycode == O)
		ft_move_light(keycode, MOVE_STEP, pic);
	else if (keycode == ROT_X_PLUS || keycode == ROT_X_MINUS || keycode == ROT_Y_PLUS || \
			keycode == ROT_Y_MINUS || keycode == ROT_Z_PLUS || keycode == ROT_Z_MINUS)
		ft_rotate_light(keycode, ROT_ANGLE, pic);
	ft_redraw_image(pic);
	return (0);
}
