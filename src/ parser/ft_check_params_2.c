/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_params_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 22:14:47 by merlich           #+#    #+#             */
/*   Updated: 2022/09/11 22:28:01 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

int	ft_check_params_sp(char **ptr)
{
	if (!ptr || !ptr[0] || !ptr[1] || !ptr[2] || !ptr[3] || ptr[4] \
		|| ft_check_position(ptr[1]) || ft_check_lparam(ft_atof(ptr[2])) \
		|| ft_check_colour(ptr[3]))
	{
        printf("MAP ERROR!\nError in sphere string!\n");
		return (1);
	}
	return (0);
}

int	ft_check_params_cy(char **ptr)
{
	if (!ptr || !ptr[0] || !ptr[1] || !ptr[2] || !ptr[3] || !ptr[4] || \
		!ptr[5] || ptr[6] \
		|| ft_check_position(ptr[1]) || ft_check_vector(ptr[2]) \
		|| ft_check_lparam(ft_atof(ptr[3])) \
		|| ft_check_lparam(ft_atof(ptr[4])) || ft_check_colour(ptr[5]))
	{
        printf("MAP ERROR!\nError in cylinder string!\n");
		return (1);
	}
	return (0);
}

int	ft_check_params_pl(char **ptr)
{
	if (!ptr || !ptr[0] || !ptr[1] || !ptr[2] || !ptr[3] || ptr[4] \
		|| ft_check_position(ptr[1]) || ft_check_vector(ptr[2]) \
		|| ft_check_colour(ptr[3]))
	{
        printf("MAP ERROR!\nError in plane string!\n");
		return (1);
	}
	return (0);
}
