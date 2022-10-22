/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dirony <dirony@21-school.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 17:55:55 by merlich           #+#    #+#             */
/*   Updated: 2022/10/22 15:58:17 by dirony           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

typedef struct s_color
{
	int	a;
	int	r;
	int	g;
	int	b;
}	t_color;

/* color_utils.c */
int	create_argb_color(int t, int r, int g, int b);
int	get_rgb_component(int color, char level);
int	change_bright(t_color clr, float ratio);
int	add_color(int color, int coef);
int	add_3_colors(int c1, int c2, int c3);

#endif
