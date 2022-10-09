/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 16:06:34 by dirony            #+#    #+#             */
/*   Updated: 2022/10/09 18:50:00 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

int	create_argb_color(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_a_color(int argb)
{
	return ((argb >> 24) & 0xFF);
}

int	get_r_color(int argb)
{
	return ((argb >> 16) & 0xFF);
}

int	get_g_color(int argb)
{
	return ((argb >> 8) & 0xFF);
}

int	get_b_color(int argb)
{
	return (argb & 0xFF);
}