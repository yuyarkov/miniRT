/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_geometry.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 20:41:51 by merlich           #+#    #+#             */
/*   Updated: 2022/10/15 21:35:44 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

int	ft_check_angle(float fov)
{
	if (fov < 0 || fov > 180)
	{
		printf("%sHorizontal field of view is out of range [0, 180]!%s\n", \
															RED_C, RESET);
		return (1);
	}
	return (0);
}

int	ft_check_ratio(float k)
{
	if (k < 0 || k > 1)
	{
		printf("%sLightning ratio is out of range [0.0, 1.0]!%s\n", \
															RED_C, RESET);
		return (1);
	}
	return (0);
}

int	ft_check_lparam(float l)
{
	if (l < 0)
	{
		printf("%sLinear parameters should be greater or equal to zero!%s\n", \
															YELLOW_C, RESET);
		return (1);
	}
	return (0);
}
