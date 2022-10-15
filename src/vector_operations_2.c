/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 20:45:59 by merlich           #+#    #+#             */
/*   Updated: 2022/10/15 18:22:25 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	vector_normalize(t_vec3 *v)
{
	double	len;

	len = vector_len(*v);
	if (len > 0)
	{
		v->x /= len;
		v->y /= len;
		v->z /= len;
	}
}

t_vec3	get_norm_vector(t_vec3 *v)
{
	double	len;

	len = vector_len(*v);
	if (len > 0)
	{
		v->x /= len;
		v->y /= len;
		v->z /= len;
	}
	return (*v);
}

t_vec3	vector_multiply(t_vec3 vector, float k)//сделать обращение по указателю, должно быть быстрее
{
	vector.x *= k;
	vector.y *= k;
	vector.z *= k;
	return (vector);
}

t_vec3	vec3_cross_product(t_vec3 a, t_vec3 b)
{
	t_vec3	result;

	result.x = a.y * b.z - a.z * b.y;
	result.y = a.z * b.x - a.x * b.z;
	result.z = a.x * b.y - a.y * b.x;
	return (result);
}
