/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_buttons_4.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 21:37:32 by merlich           #+#    #+#             */
/*   Updated: 2022/10/15 19:04:07 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	ft_move_light(int keycode, float step, t_data *pic)
{
	t_light	*light;

	light = pic->scene_ptr->light;
	if (keycode == K)
		light->origin.y += step;
	else if (keycode == I)
		light->origin.y -= step;
	else if (keycode == J)
		light->origin.x -= step;
	else if (keycode == L)
		light->origin.x += step;
	else if (keycode == U)
		light->origin.z += step;
	else if (keycode == O)
		light->origin.z -= step;
	printf("light.X = %f\n", light->origin.x);
	printf("light.Y = %f\n", light->origin.y);
	printf("light.Z = %f\n", light->origin.z);
}
