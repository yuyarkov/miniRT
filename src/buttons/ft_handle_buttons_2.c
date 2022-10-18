/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_buttons_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dirony <dirony@21-school.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 19:59:47 by merlich           #+#    #+#             */
/*   Updated: 2022/10/18 20:47:13 by dirony           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	ft_resize_figure(int step, t_data *pic)
{
	t_figure	*figures;

	figures = pic->scene_ptr->figures;
	while (figures)
	{
		if (figures->type == SPHERE)
		{
			figures->radius += step;
			if (figures->radius < 0)
				figures->radius = 0;
		}
		else if (figures->type == CYLINDER)
		{
			figures->radius += step;
			if (figures->radius < 0)
				figures->radius = 0;
			figures->height += step;
			if (figures->height < 0)
				figures->height = 0;
		}
		figures = figures->next;
	}
}

void	ft_move_figure(int keycode, int step, t_data *pic)
{
	t_figure	*figures;

	figures = pic->scene_ptr->figures;
	while (figures)
	{
		if (keycode == W)
			figures->center.y -= step;
		else if (keycode == S)
			figures->center.y += step;
		else if (keycode == A)
			figures->center.x -= step;
		else if (keycode == D)
			figures->center.x += step;
		else if (keycode == SPACE || keycode == X || keycode == E)
			figures->center.z -= step;
		else if (keycode == SHIFT || keycode == Z || keycode == Q)
			figures->center.z += step;
		figures = figures->next;
	}
}

void	rotate_figure(int keycode, int angle, t_data *pic)
{
	t_figure	*figures;

	figures = pic->scene_ptr->figures;
	while (figures)
	{
		if (keycode == T)
			figures->norm_vector = rotate_x(figures->norm_vector, angle);
		else if (keycode == G)
			figures->norm_vector = rotate_x(figures->norm_vector, -angle);
		else if (keycode == H)
			figures->norm_vector = rotate_y(figures->norm_vector, angle);
		else if (keycode == F)
			figures->norm_vector = rotate_y(figures->norm_vector, -angle);
		else if (keycode == Y)
			figures->norm_vector = rotate_z(figures->norm_vector, angle);
		else if (keycode == R)
			figures->norm_vector = rotate_z(figures->norm_vector, -angle);
		figures = figures->next;
	}
}
