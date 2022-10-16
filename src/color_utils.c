/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dirony <dirony@21-school.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 16:06:34 by dirony            #+#    #+#             */
/*   Updated: 2022/10/16 18:43:55 by dirony           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

int	create_argb_color(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_rgb_component(int color, char component)
{
	if (component == 'R')
		return ((color >> 16) & 0xFF);
	else if (component == 'G')
		return ((color >> 8) & 0xFF);
	else if (component == 'B')
		return (color & 0xFF);
	return (0);
}

int	change_bright(t_color color, float ratio)
{
	int	res;
	int	r;
	int	g;
	int	b;

	r = color.r * ratio;
	if (r > 255)
		r = 255;
	else if (r < 0)
		r = 0;
	g = color.g * ratio;
	if (g > 255)
		g = 255;
	else if (g < 0)
		g = 0;
	b = color.b * ratio;
	if (b > 255)
		b = 255;
	else if (b < 0)
		b = 0;
	res = (r << 16) | (g << 8) | b;
	return (res);
}

int	add_color(int color, int coef)
{
	int	r;
	int	g;
	int	b;
	int	res;

	r = get_rgb_component(color, 'R') + coef;
	if (r > 255)
		r = 255;
	else if (r < 0)
		r = 0;
	g = get_rgb_component(color, 'G') + coef;
	if (g > 255)
		g = 255;
	else if (g < 0)
		g = 0;
	b = get_rgb_component(color, 'B') + coef;
	if (b > 255)
		b = 255;
	else if (b < 0)
		b = 0;
	res = (r << 16) | (g << 8) | b;
	return (res);
}

int	add_3_colors(int c1, int c2, int c3)
{
	int	res;
	int	r;
	int	g;
	int	b;

	r = get_rgb_component(c1, 'R') + get_rgb_component(c2, 'R') + get_rgb_component(c3, 'R');
	if (r > 255)
		r = 255;
	else if (r < 0)
		r = 0;
	g = get_rgb_component(c1, 'G') + get_rgb_component(c2, 'G') + get_rgb_component(c3, 'G');
	if (g > 255)
		g = 255;
	else if (g < 0)
		g = 0;
	b = get_rgb_component(c1, 'B') + get_rgb_component(c2, 'B') + get_rgb_component(c3, 'B');
	if (b > 255)
		b = 255;
	else if (b < 0)
		b = 0;
	res = r << 16 | g << 8 | b;
	return (res);
}
