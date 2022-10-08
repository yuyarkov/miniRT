/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dirony <dirony@21-school.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 16:49:20 by dirony            #+#    #+#             */
/*   Updated: 2022/10/08 16:50:04 by dirony           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

typedef struct s_sphere
{
	t_vec3		center;
	double		radius;
}				t_sphere;

t_sphere		*sphere_create(t_vec3 center, float radius);
t_vec3			sphere_get_normal(t_vec3 point, t_sphere sphere);

#endif