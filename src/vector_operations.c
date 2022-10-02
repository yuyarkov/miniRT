#include "miniRT.h"

t_vec3	ft_build_vector(float x, float y, float z)
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

void	ft_normalize_vector(t_vec3 *v)
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

t_vec3	vec3_cross_product(t_vec3 a, t_vec3 b)
{
	t_vec3	result;

	result.x = a.y * b.z - a.z * b.y;
	result.y = a.z * b.x - a.x * b.z;
	result.z = a.x * b.y - a.y * b.x;
	return (result);
}


