/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_vector.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 19:50:37 by merlich           #+#    #+#             */
/*   Updated: 2022/09/11 21:55:22 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

static int	ft_perror_range(char **ptr)
{
	printf("Error!\nA value of vector`s coordinates is out of range\n");
	ft_free_split(ptr);
	return 1;
}

static int	ft_perror_count(char **ptr)
{
	printf("Error!\nWrong number of parameters for vector representation (x,y,z)\n");
	ft_free_split(ptr);
	return 1;
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
			return ft_perror_range(ptr);
		i++;
	}
	if (i != 3)
		return ft_perror_count(ptr);
	ft_free_split(ptr);
	return 0;
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
		return ft_perror_count(ptr);
	ft_free_split(ptr);
	return 0;
}
