/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 17:55:32 by merlich           #+#    #+#             */
/*   Updated: 2022/10/15 19:15:33 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "../includes/miniRT.h"

typedef struct s_ray
{
	t_vec3			origin;
	t_vec3			direction;
	struct s_ray	*next;
}					t_ray;

t_ray	ray_create(t_vec3 origin, t_vec3 direction);
t_vec3	ray_by_x_y(int x, int y, t_scene *scene);

#endif
