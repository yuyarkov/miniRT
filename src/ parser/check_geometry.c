/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_geometry.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 20:41:51 by merlich           #+#    #+#             */
/*   Updated: 2022/09/04 20:30:59 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

int	ft_check_angle(float fov)
{
	if (fov < 0 || fov > 180)
	{
		printf("Error!\nHorizontal field of view is out of range [0, 180]");
		return 1;
	}
	return 0;
}

int	ft_check_ratio(float k)
{
	if (k < 0 || k > 1)
	{
		printf("Error!\nLightning ratio is out of range [0.0, 1.0]");
		return 1;
	}
	return 0;
}

int	ft_check_lparam(float l)
{
	if (l < 0)
	{
		printf("Error!\nLinear parameters should be greater than/(equal to) zero");
		return 1;
	}
	return 0;
}
