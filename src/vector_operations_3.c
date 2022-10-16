/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations_3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dirony <dirony@21-school.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 20:45:59 by merlich           #+#    #+#             */
/*   Updated: 2022/10/16 19:19:39 by dirony           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

t_vec3	reflect_vector(t_vec3 direction, t_vec3 normale)
{
	t_vec3	reflect;
	t_vec3	tmp;

	tmp = vector_multiply(normale, (2 * scalar_product(normale, direction)));
	reflect = vector_sub(direction, tmp);
	vector_normalize(&reflect);
	return (reflect);
}

float	get_distance(t_vec3 a, t_vec3 b)
{
	float	distance;
	t_vec3	sub;

	sub = vector_sub(b, a);
	distance = vector_len(sub);
	return (distance);
}
