/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_buttons_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 19:59:47 by merlich           #+#    #+#             */
/*   Updated: 2022/10/02 19:59:48 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/miniRT.h"

void	ft_resize(int step, t_data *pic)
{
	t_figure	*figures;

	figures = pic->scene_ptr->figures;
	while (figures)
	{
		if (figures->type == SPHERE)
		{
			figures->diameter += step;
			if (figures->diameter < 0)
				figures->diameter = 0;
		}
		else if (figures->type == CYLINDER)
		{
			figures->diameter += step;
			if (figures->diameter < 0)
				figures->diameter = 0;
			figures->height += step;
			if (figures->height < 0)
				figures->height = 0;
		}
		figures = figures->next;
	}
}

void	ft_move(int keycode, int step, t_data *pic)
{
	t_figure	*figures;

	figures = pic->scene_ptr->figures;
	while (figures)
	{
		if (keycode == W)
			figures->position.y -= step;
		else if (keycode == S)
			figures->position.y += step;
		else if (keycode == A)
			figures->position.x -= step;
		else if (keycode == D)
			figures->position.x += step;
		else if (keycode == SPACE || keycode == X)
			figures->position.z -= step;
		else if (keycode == SHIFT || keycode == Z)
			figures->position.z += step;
		figures = figures->next;
	}
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
	// printf("FOV = %d\n", pic->scene_ptr->camera->fov);
}

void	ft_rotate_figure(int keycode, int angle, t_data *pic)
{
	t_figure	*figures;

	figures = pic->scene_ptr->figures;
	while (figures)
	{
		if (keycode == Q)
		{
			printf("x1 = %f\ny1 = %f\nz1 = %f\n", figures->norm_vector.x, figures->norm_vector.y, figures->norm_vector.z);
			figures->norm_vector = ft_rotate_x(figures->norm_vector, angle);
			printf("x2 = %f\ny2 = %f\nz2 = %f\n", figures->norm_vector.x, figures->norm_vector.y, figures->norm_vector.z);
		}
		else if (keycode == E)
		{
			printf("x1 = %f\ny1 = %f\nz1 = %f\n", figures->norm_vector.x, figures->norm_vector.y, figures->norm_vector.z);
			figures->norm_vector = ft_rotate_x(figures->norm_vector, -angle);
			printf("x1 = %f\ny1 = %f\nz1 = %f\n", figures->norm_vector.x, figures->norm_vector.y, figures->norm_vector.z);
		}
		figures = figures->next;
	}
}
