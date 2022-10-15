/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figures_utils_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 20:27:27 by merlich           #+#    #+#             */
/*   Updated: 2022/10/15 22:07:31 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	ft_fill_color(t_color *color, int *colour, char **p2)
{
	color->a = 1;
	color->r = ft_atoi(p2[0]);
	color->g = ft_atoi(p2[1]);
	color->b = ft_atoi(p2[2]);
	*colour = create_argb_color(color->a, color->r, color->g, color->b);
}

void	ft_fill_center(t_vec3 *center, char **p1)
{
	center->x = ft_atof(p1[0]);
	center->y = ft_atof(p1[1]);
	center->z = ft_atof(p1[2]);
}

void	ft_fill_norm_vector(t_vec3 *norm_vector, char **p2)
{
	norm_vector->x = ft_atof(p2[0]);
	norm_vector->y = ft_atof(p2[1]);
	norm_vector->z = ft_atof(p2[2]);
}
