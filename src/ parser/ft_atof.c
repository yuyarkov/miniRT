/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 21:19:57 by merlich           #+#    #+#             */
/*   Updated: 2022/10/02 17:20:12 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

float	ft_atof(char *str)
{
	int		count;
	float	res;
	int		i;
	int		f;
	int		tmp;

	count = 0;
	res = 0;
	i = ft_atoi(str);
	f = ft_atoi((ft_strchr(str, '.')));
	tmp = f;
	while ((tmp % 10) != 0)
	{
		tmp = tmp / 10;
		count++;
	}
	res = i + f * pow(10, -count);
	return res;
}
