/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_params_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 21:21:02 by merlich           #+#    #+#             */
/*   Updated: 2022/09/11 22:27:31 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

int	ft_check_params_a(char **ptr)
{
	if (!ptr || !ptr[0] || !ptr[1] || !ptr[2] || ptr[3] \
		|| ft_check_lparam(ft_atof(ptr[1])) || ft_check_colour(ptr[2]))
	{
		printf("MAP ERROR!\nError in ambient light string!\n");
		return (1);
	}
	return (0);
}

int	ft_check_params_c(char **ptr)
{
	if (!ptr || !ptr[0] || !ptr[1] || !ptr[2] || !ptr[3] || ptr[4] \
		|| ft_check_position(ptr[1]) || ft_check_vector(ptr[2]) \
		|| ft_check_angle(ft_atof(ptr[3])))
	{
		printf("MAP ERROR!\nError in camera string!\n");
		return (1);
	}
	return (0);
}

int	ft_check_params_l(char **ptr)
{
	if (!ptr || !ptr[0] || !ptr[1] || !ptr[2] || !ptr[3] || ptr[4] \
		|| ft_check_position(ptr[1]) || ft_check_ratio(ft_atof(ptr[2])) \
		|| ft_check_colour(ptr[3]))
	{
		printf("MAP ERROR!\nError in light string!\n");
		return (1);
	}
	return (0);
}
