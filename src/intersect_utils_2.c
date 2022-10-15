/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:46:23 by merlich           #+#    #+#             */
/*   Updated: 2022/10/15 18:26:48 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

t_vec3	ft_cylinder_norm(t_figure *cyl, t_vec3 *inter_point)
{
	t_vec3	norm;
	t_vec3	top_center;
	t_vec3	pt;
	t_vec3	tmp;
	float	t;

	tmp = vector_multiply(cyl->norm_vector, cyl->height);
	top_center = vector_sum(cyl->center, tmp);
	if (vector_len(vector_sub(*inter_point, cyl->center)) < cyl->radius)
		norm = vector_multiply(cyl->center, -1);
	else if (vector_len(vector_sub(*inter_point, top_center)) < cyl->radius)
		norm = get_norm_vector(&(cyl->norm_vector));
	else
	{
		tmp = vector_sub(*inter_point, cyl->center);
		t = vector_s_prod(tmp, cyl->norm_vector);
		tmp = vector_multiply(cyl->norm_vector, t);
		pt = vector_sum(cyl->center, tmp);
		tmp = vector_sub(*inter_point, pt);
		norm = get_norm_vector(&tmp);
	}
	norm = get_norm_vector(&norm);
	return (norm);
}

float	ft_calc_t(float ca_co_cp, float cadir, float caca, float res)
{
	float	t;

	if (res < 0)
		t = (0 - ca_co_cp) / cadir;
	else
		t = (caca - ca_co_cp) / cadir;
	return (t);
}

float	ft_cylinder_intersect_2(t_figure *cyl, t_vec3 *cam_origin, \
											t_vec3 *direction, t_discrmn box)
{
	box.tmp = vector_sub(*cam_origin, cyl->center);
	box.res = vector_s_prod(box.ca, box.tmp) + \
			((-box.b - sqrt(box.discr)) / box.a) * vector_s_prod(box.ca, *direction);
	if (box.res > 0 && box.res < vector_s_prod(box.ca, box.ca))
		return (((-box.b - sqrt((box.b * box.b - box.a * box.c))) / box.a));
	box.tmp = vector_sub(*cam_origin, cyl->center);
	box.res = ft_calc_t(vector_s_prod(box.ca, box.tmp), vector_s_prod(box.ca, *direction), \
											vector_s_prod(box.ca, box.ca), box.res);
	if (fabs(box.b + box.a * box.res) < sqrt(box.discr))
		return (box.res);
	return (0);
}

float	ft_cylinder_intersect(t_figure *cyl, t_vec3 *cam_origin, \
											t_vec3 *direction, t_discrmn box)
{
	box.tmp = vector_multiply(cyl->norm_vector, cyl->height);
	box.tmp = vector_sum(cyl->center, box.tmp);
	box.ca = vector_sub(box.tmp, cyl->center);
	box.a = vector_s_prod(box.ca, box.ca) - vector_s_prod(box.ca, *direction) * \
													vector_s_prod(box.ca, *direction);
	box.tmp = vector_sub(*cam_origin, cyl->center);
	box.b = vector_s_prod(box.ca, box.ca) * vector_s_prod(box.tmp, *direction) - \
						vector_s_prod(box.ca, box.tmp) * vector_s_prod(box.ca, *direction);
	box.tmp = vector_sub(*cam_origin, cyl->center);
	box.c = vector_s_prod(box.ca, box.ca) * vector_s_prod(box.tmp, box.tmp) - \
					vector_s_prod(box.ca, box.tmp) * vector_s_prod(box.ca, box.tmp) - \
								cyl->radius * cyl->radius * vector_s_prod(box.ca, box.ca);
	box.discr = box.b * box.b - box.a * box.c;
	if (box.discr < 0)
		return (0);
	box.res = ft_cylinder_intersect_2(cyl, cam_origin, direction, box);
	return (box.res);
}
