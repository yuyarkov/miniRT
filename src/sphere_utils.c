/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dirony <dirony@21-school.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 18:42:24 by dirony            #+#    #+#             */
/*   Updated: 2022/09/18 16:59:17 by dirony           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

int	get_darker_color_from_radius(float h, int c)
{
	return (create_argb_color(h, get_r_color(c), get_g_color(c), get_b_color(c)));
}

int sphere_intersect(t_vec3 ray, t_vec3 center, float radius, int color)
{
	float dist_to_sphere;
	float h;
	
	//print_vector(ray, "ray: ");
	
	dist_to_sphere = vector_scalar_product(ray, center);
	vector_stretch(&ray, dist_to_sphere); //переделать под временный луч, иначе этот луч не получится использовать дальше. Или может получится, нормализовать его снова и т.д.
	h = vector_len(vector_minus(ray, center));
    if (h < (radius * 0.999))
		return get_darker_color_from_radius(h / radius * 256, color); // есть пересечение, верну цвет для эксперимента
	else
		return 0;
}
