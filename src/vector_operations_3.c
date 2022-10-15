/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations_3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 20:45:59 by merlich           #+#    #+#             */
/*   Updated: 2022/10/15 18:22:25 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

t_vec3	ft_reflect_vector(t_vec3 direction, t_vec3 normale)
{
	t_vec3	reflect;
	t_vec3	tmp;

	tmp = vector_multiply(normale, (2 * vector_s_prod(normale, direction)));
	reflect = vector_sub(direction, tmp);
	reflect = get_norm_vector(&reflect);
	return (reflect);
}

float	ft_find_dist(t_vec3 a, t_vec3 b)
{
	float	dist;
	t_vec3	sub;

	sub = vector_sub(b, a);
	dist = vector_len(sub);
	return (dist);
}
