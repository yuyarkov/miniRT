/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dirony <dirony@21-school.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 18:42:24 by dirony            #+#    #+#             */
/*   Updated: 2022/09/16 19:23:21 by dirony           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

int sphere_intersect(t_vec3 ray_origin, t_vec3 ray_direction, t_vec3 center, float radius )
{
    t_vec3 oc;
	float b;
	float h;
	
	//print_vector(ray_origin, "ray_origin: ");
	oc = vector_minus(ray_origin, center);
	//print_vector(oc, "oc: ");
    b = vector_dot_product(oc, ray_direction);
    h = b * b - vector_dot_product(oc, oc) - radius * radius;;
	//printf("inside sphere_intersect, h: %f\n", h);
    if (h < 0.0)
		return 0; //vec2(-1.0); // no intersection
	else
		return 1;
    //h = sqrt(h); это какая-то дополнительная информация, может пригодится дальше
    //return vec2( -b-h, -b+h );
}
