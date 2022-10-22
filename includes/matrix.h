/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dirony <dirony@21-school.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 17:03:23 by dirony            #+#    #+#             */
/*   Updated: 2022/10/22 17:04:19 by dirony           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

typedef struct s_matrix
{
	float	d[4][4];
}   t_matrix;

t_vec3			multiply_by_matrix(t_vec3 p, t_matrix m);
t_matrix		look_at(t_vec3 origin, t_vec3 cam_direction);

#endif