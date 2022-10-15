/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 21:35:22 by dirony            #+#    #+#             */
/*   Updated: 2022/10/15 18:09:12 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	my_mlx_pixel_put(t_data *pic, int x, int y, int color)
{
	char	*dest;

	if (x > 0 && x < (WIN_WIDTH - M_LEFT) && y > 0 && y < (WIN_HEIGHT - M_TOP))
	{
		dest = pic->addr + (y * pic->line_len + x * (pic->bits_per_p / 8));
		*(unsigned int *)dest = color;
	}
}
