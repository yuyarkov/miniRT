/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dirony <dirony@21-school.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 16:44:14 by dirony            #+#    #+#             */
/*   Updated: 2022/10/08 20:05:31 by dirony           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec3	vector_create(float x, float y, float z)
{
	t_vec3	result;

	result.x = x;
	result.y = y;
	result.z = z;
	return (result);
}

float	vector_len(t_vec3 v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

t_vec3 vector_sum(t_vec3 first, t_vec3 second)
{
    t_vec3	result;

	result.x = first.x + second.x;
	result.y = first.y + second.y;
	result.z = first.z + second.z;
	return (result);
}

t_vec3 vector_minus(t_vec3 first, t_vec3 second)
{
    t_vec3	result;

	result.x = first.x - second.x;
	result.y = first.y - second.y;
	result.z = first.z - second.z;
	return (result);
}

float	vector_scalar_product(t_vec3 a, t_vec3 b) //скалярное произведение
{
	float	result;

	result = (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
	return (result);
}

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

void	vector_stretch(t_vec3 *v, float k)
{
	v->x *= k;
	v->y *= k;
	v->z *= k;
}

t_vec3	vector_multiply(t_vec3 vec1, double x) //то же самое, что stretch, только эта функция выдаёт вектор результатом
{
	t_vec3	result;

	result.x = vec1.x * x;
	result.y = vec1.y * x;
	result.z = vec1.z * x;
	return (result);
}

t_vec3	vector_cross_product(t_vec3 a, t_vec3 b)
{
	t_vec3	result;

	result.x = a.y * b.z - a.z * b.y;
	result.y = a.z * b.x - a.x * b.z;
	result.z = a.x * b.y - a.y * b.x;
	return (result);
}

double	vector_dist(t_vec3 vec1, t_vec3 vec2)
{
	return (sqrt(pow(vec2.x - vec1.x, 2)
			+ pow(vec2.y - vec1.y, 2)
			+ pow(vec2.z - vec1.z, 2)));
}
