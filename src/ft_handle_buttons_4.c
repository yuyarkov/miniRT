/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_buttons_4.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 21:37:32 by merlich           #+#    #+#             */
/*   Updated: 2022/10/08 22:12:52 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	ft_move_light(int keycode, float step, t_data *pic)
{
	t_light	*ray;

	ray = pic->scene_ptr->light;

	if (keycode == K)
		ray->origin.y += step;
	else if (keycode == I)
		ray->origin.y -= step;
	else if (keycode == J)
		ray->origin.x -= step;
	else if (keycode == L)
		ray->origin.x += step;
	else if (keycode == U)
		ray->origin.z += step;
	else if (keycode == O)
		ray->origin.z -= step;
	printf("RAY.X = %f\n", ray->origin.x);
	printf("RAY.Y = %f\n", ray->origin.y);
	printf("RAY.Z = %f\n", ray->origin.z);
}

void	ft_rotate_light(int keycode, float angle, t_data *pic)
{
	t_light	*ray;

	ray = pic->scene_ptr->light;

	if (keycode == ROT_X_PLUS)
		ray. -= angle;
	else if (keycode == ROT_X_MINUS)
		ray->origin.y -= angle;
	else if (keycode == ROT_Y_PLUS)
		ray->origin.z -= angle;
	else if (keycode == ROT_Y_MINUS)
		ray->origin.z += angle;
	else if (keycode == ROT_Z_PLUS)
		ray->origin.z -= angle;
	else if (keycode == ROT_Z_MINUS)
		ray->origin.z += angle;

}
