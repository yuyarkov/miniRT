/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 18:51:14 by merlich           #+#    #+#             */
/*   Updated: 2022/10/09 18:57:17 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

int	ft_rgb(int color, char level)
{
	if (level == 'R')
		return ((color >> 16) & 0xFF);
	else if (level == 'G')
		return ((color >> 8) & 0xFF);
	else if (level == 'B')
		return (color & 0xFF);
	return (0);
}

int	ft_mul_clr(t_color clr, float ratio)
{
	int	res;
	int	r;
	int	g;
	int	b;

	r = clr.r * ratio;
	if (r > 255)
		r = 255;
	else if (r < 0)
		r = 0;
	g = clr.g * ratio;
	if (g > 255)
		g = 255;
	else if (g < 0)
		g = 0;
	b = clr.b * ratio;
	if (b > 255)
		b = 255;
	else if (b < 0)
		b = 0;
	res = (r << 16) | (g << 8) | b;
	return (res);
}

int	ft_add_clr(int color, int coef)
{
	int	r;
	int	g;
	int	b;
	int	res;

	r = ft_rgb(color, 'R') + coef;
	if (r > 255)
		r = 255;
	else if (r < 0)
		r = 0;
	g = ft_rgb(color, 'G') + coef;
	if (g > 255)
		g = 255;
	else if (g < 0)
		g = 0;
	b = ft_rgb(color, 'B') + coef;
	if (b > 255)
		b = 255;
	else if (b < 0)
		b = 0;
	res = (r << 16) | (g << 8) | b;
	return (res);
}

int	ft_add_clr3(int c1, int c2, int c3)
{
	int	res;
	int	r;
	int	g;
	int	b;

	r = ft_rgb(c1, 'R') + ft_rgb(c2, 'R') + ft_rgb(c3, 'R');
	if (r > 255)
		r = 255;
	else if (r < 0)
		r = 0;
	g = ft_rgb(c1, 'G') + ft_rgb(c2, 'G') + ft_rgb(c3, 'G');
	if (g > 255)
		g = 255;
	else if (g < 0)
		g = 0;
	b = ft_rgb(c1, 'B') + ft_rgb(c2, 'B') + ft_rgb(c3, 'B');
	if (b > 255)
		b = 255;
	else if (b < 0)
		b = 0;
	res = r << 16 | g << 8 | b;
	return (res);
}
