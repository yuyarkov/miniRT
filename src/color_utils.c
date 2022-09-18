/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dirony <dirony@21-school.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 16:06:34 by dirony            #+#    #+#             */
/*   Updated: 2022/09/18 16:08:24 by dirony           ###   ########.fr       */
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