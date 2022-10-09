/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colour.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 19:50:37 by merlich           #+#    #+#             */
/*   Updated: 2022/09/11 21:39:00 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	ft_free_split(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

static int	ft_perror_range(char **ptr)
{
	printf("Error!\nA value of colour is out of range\n");
	ft_free_split(ptr);
	return 1;
}

static int	ft_perror_count(char **ptr)
{
	printf("Error!\nWrong number of parameters for colour representation (R,G,B)\n");
	ft_free_split(ptr);
	return 1;
}

int	ft_check_colour(char *str)
{
	int		i;
	int		num;
	char	**ptr;

	i = 0;
	num = 0;
	ptr = ft_split(str, ',');
	while (ptr[i])
	{
		num = ft_atoi(ptr[i]);
		if (num < 0 || num > 255)
			return ft_perror_range(ptr);
		i++;
	}
	if (i != 3)
		return ft_perror_count(ptr);
	ft_free_split(ptr);
	return 0;
}
