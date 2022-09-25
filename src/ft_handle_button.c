/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_button.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 20:22:22 by merlich           #+#    #+#             */
/*   Updated: 2022/09/25 20:29:47 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

int ft_handle_button(int keycode, t_data *pic)
{
	printf("button = %d\n", keycode);
	if (keycode == 53)
	{
		printf("ESC\n");
		mlx_destroy_image(pic->mlx, pic->img);
		mlx_destroy_window(pic->addr, pic->window);
		exit(EXIT_SUCCESS);
	}
	else if (keycode == 27)
	{
		printf("-\n");
		// scene->ambient_head = NULL;
	}
	else if (keycode == 24)
	{
		printf("+\n");
		// scene->ambient_head = NULL;
	}
	else if (keycode == 13)
	{
		printf("W\n");
		// scene->ambient_head = NULL;
	}
	else if (keycode == 0)
	{
		printf("A\n");
		// scene->ambient_head = NULL;
	}
	else if (keycode == 1)
	{
		printf("S\n");
		// scene->ambient_head = NULL;
	}
	else if (keycode == 2)
	{
		printf("D\n");
		// scene->ambient_head = NULL;
	}
	else if (keycode == 12)
	{
		printf("Q\n");
		// scene->ambient_head = NULL;
	}
	else if (keycode == 14)
	{
		printf("E\n");
		// scene->ambient_head = NULL;
	}
		else if (keycode == 257 || keycode == 258)
	{
		printf("shift\n");
		// scene->ambient_head = NULL;
	}
		else if (keycode == 49)
	{
		printf("space\n");
		// scene->ambient_head = NULL;
	}
	return (0);
}

int ft_just_exit(t_data *pic)
{
	mlx_destroy_image(pic->mlx, pic->img);
	mlx_destroy_window(pic->addr, pic->window);
	exit(EXIT_SUCCESS);
	return (0);
}
