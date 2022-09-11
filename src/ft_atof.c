/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 21:19:57 by merlich           #+#    #+#             */
/*   Updated: 2022/09/11 20:56:33 by merlich          ###   ########.fr       */
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
		// printf("%d\n", tmp);
		tmp = tmp / 10;
		count++;
	}
	// printf("i = %d\n", i);
	// printf("f = %d\n", f);
	// printf("float_part = %f\n", f * pow(10, -count));
	res = i + f * pow(10, -count);
	// printf("res = %f\n", res);
	return res;
}
