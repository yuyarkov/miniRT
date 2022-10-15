/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_vector.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 19:50:37 by merlich           #+#    #+#             */
/*   Updated: 2022/10/15 21:35:49 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

static int	ft_perror_range(char **ptr)
{
	printf("%sThe value of vector`s coordinates is out of range!%s\n", \
															RED_C, RESET);
	ft_free_split(ptr);
	return (1);
}

static int	ft_perror_count(char **ptr)
{
	printf("%sWrong number of parameters to represent vector (x,y,z)!%s\n", \
															RED_C, RESET);
	ft_free_split(ptr);
	return (1);
}

int	ft_check_vector(char *str)
{
	int		i;
	float	num;
	char	**ptr;

	i = 0;
	num = 0;
	ptr = ft_split(str, ',');
	while (ptr[i])
	{
		num = ft_atof(ptr[i]);
		if (num < -1 || num > 1)
			return (ft_perror_range(ptr));
		i++;
	}
	if (i != 3)
		return (ft_perror_count(ptr));
	ft_free_split(ptr);
	return (0);
}

int	ft_check_position(char *str)
{
	int		i;
	char	**ptr;

	i = 0;
	ptr = ft_split(str, ',');
	while (ptr[i])
		i++;
	if (i != 3)
		return (ft_perror_count(ptr));
	ft_free_split(ptr);
	return (0);
}
