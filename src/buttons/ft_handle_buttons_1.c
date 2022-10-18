/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_buttons_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dirony <dirony@21-school.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 20:22:22 by merlich           #+#    #+#             */
/*   Updated: 2022/10/18 21:06:27 by dirony           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	ft_redraw_image(t_data *pic)
{
	mlx_destroy_image(pic->mlx, pic->img);
	pic->img = mlx_new_image(pic->mlx, WIN_WIDTH, WIN_HEIGHT);
	pic->addr = mlx_get_data_addr(pic->img, &pic->bits_per_p,
			&pic->line_len, &pic->endian);
	render(pic, pic->scene_ptr);
	mlx_put_image_to_window(pic->mlx, pic->window, pic->img, M_LEFT, M_TOP);
}

int	ft_just_exit(t_data *pic)
{
	mlx_destroy_image(pic->mlx, pic->img);
	mlx_destroy_window(pic->addr, pic->window);
	exit(EXIT_SUCCESS);
	return (0);
}

static void	ft_handle_buttons_2(int keycode, t_data *pic)
{
	if (keycode == ESC)
		ft_just_exit(pic);
	else if (keycode == MINUS)
		ft_resize_figure(-SIZE_STEP, pic);
	else if (keycode == PLUS)
		ft_resize_figure(SIZE_STEP, pic);
	else if (keycode == W || keycode == A || keycode == S || keycode == D || \
			keycode == SHIFT || keycode == X || keycode == SPACE || \
			keycode == Z || keycode == Q || keycode == E)
		ft_move_figure(keycode, MOVE_STEP, pic);
	else if (keycode == F || keycode == H || keycode == T || keycode == G || \
			keycode == R || keycode == Y)
		rotate_figure(keycode, ROT_ANGLE, pic);
}

int	ft_handle_buttons(int keycode, t_data *pic)
{
	printf("cylinder height: %f, button code = %d\n", pic->scene_ptr->figures->height, keycode);
	ft_handle_buttons_2(keycode, pic);
	if (keycode == FOV_PLUS || keycode == FOV_MINUS)
		ft_change_fov(keycode, CAM_STEP, pic);
	else if (keycode == UP || keycode == DOWN || keycode == LEFT || \
			keycode == RIGHT || keycode == FORWARD || keycode == BACKWARD)
		ft_move_camera(keycode, MOVE_STEP, pic);
	else if (keycode == ROT_UP || keycode == ROT_DOWN || keycode == ROT_LEFT \
		|| keycode == ROT_RIGHT || keycode == ROT_FRONT || keycode == ROT_BACK)
		rotate_camera(keycode, ROT_ANGLE, pic);
	else if (keycode == I || keycode == K || keycode == J || \
			keycode == L || keycode == U || keycode == O)
		ft_move_light(keycode, LIGHT_STEP, pic);
	ft_redraw_image(pic);
	printf("after redraw, cylinder height: %f, button code = %d\n", pic->scene_ptr->figures->height, keycode);
	return (0);
}
