/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dirony <dirony@21-school.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 16:06:34 by dirony            #+#    #+#             */
/*   Updated: 2022/10/08 17:29:27 by dirony           ###   ########.fr       */
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

t_color	int_to_color(int color)
{
	t_color	new;

	new.t = (color & (0xFF << 24)) >> 24;
	new.r = (color & (0xFF << 16)) >> 16;
	new.g = (color & (0xFF << 8)) >> 8;
	new.b = color & 0xFF;
	return (new);
}

int	color_to_int(t_color c)
{
	int	result;

	result = (c.t << 24);
	result = result | (c.r << 16);
	result = result | (c.g << 8);
	result = result | (c.b);
	return (result);
}

t_color_r	from_color_to_r(t_color c)
{
	t_color_r	result;

	result.r = c.r / 255.;
	result.g = c.g / 255.;
	result.b = c.b / 255.;
	result.a = c.t / 255.;
	return (result);
}

t_color_r	from_int_to_r(int c)
{
	t_color		tmp;
	t_color_r	result;

	tmp = int_to_color(c);
	result.r = (float)tmp.r / 255;
	result.g = (float)tmp.g / 255;
	result.b = (float)tmp.b / 255;
	result.a = (float)tmp.t / 255;
	return (result);
}

t_color_r	color_r_light(t_color_r a, t_color_r b)
{
	t_color_r	result;

	result.r = fmax(a.r, b.r);
	result.g = fmax(a.g, b.g);
	result.r = fmax(a.b, b.b);
	result.a = fmax(a.a, b.a);
	return (result);
}
