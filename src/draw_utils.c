/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dirony <dirony@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 21:35:22 by dirony            #+#    #+#             */
/*   Updated: 2021/12/11 15:41:14 by dirony           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	my_mlx_pixel_put(t_data *pic, int x, int y, int color)
{
	char	*dest;

	if (x > 0 && x < (WINDOW_WIDTH - M_LEFT) && y > 0 && y < (WINDOW_HEIGHT - M_TOP))
	{
		dest = pic->addr + (y * pic->line_len + x * (pic->bits_per_p / 8));
		*(unsigned int *)dest = color;
	}
}
