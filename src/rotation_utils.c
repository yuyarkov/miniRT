/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dirony <dirony@21-school.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 19:16:53 by merlich           #+#    #+#             */
/*   Updated: 2022/10/18 20:15:49 by dirony           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

t_vec3	rotate_x(t_vec3 vector, float phi)
{
	float	new_y;
	float	new_z;

	new_y = vector.y * cos(phi) + vector.z * sin(phi);
	new_z = -vector.y * sin(phi) + vector.z * cos(phi);
	vector = build_vector(vector.x, new_y, new_z);
	vector_normalize(&vector);
	return (vector);
}

t_vec3	rotate_y(t_vec3 vector, float phi)
{
	float	new_x;
	float	new_z;

	new_x = vector.x * cos(phi) - vector.z * sin(phi);
	new_z = vector.x * sin(phi) + vector.z * cos(phi);
	vector = build_vector(new_x, vector.y, new_z);
	vector_normalize(&vector);
	return (vector);
}

t_vec3	rotate_z(t_vec3 vector, float phi)
{
	float	new_x;
	float	new_y;

	new_x = vector.x * cos(phi) - vector.y * sin(phi);
	new_y = vector.x * sin(phi) + vector.y * cos(phi);
	vector = build_vector(new_x, new_y, vector.z);
	vector_normalize(&vector);
	return (vector);
}

t_vec3	rotate_dir(t_vec3 dir, t_camera *camera)
{
	float	n_x;
	float	n_y;
	float	n_z;
	float	a;

	a = camera->angle_y;
	n_x = dir.x * cos(a) - dir.z * sin(a);
	n_z = dir.x * sin(a) + dir.z * cos(a);
	dir = build_vector(n_x, dir.y, n_z);
	vector_normalize(&dir);
	a = camera->angle_z;
	n_x = dir.x * cos(a) - dir.y * sin(a);
	n_y = dir.x * sin(a) + dir.y * cos(a);
	dir = build_vector(n_x, n_y, dir.z);
	vector_normalize(&dir);
	return (dir);
}
