/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 17:55:46 by merlich           #+#    #+#             */
/*   Updated: 2022/10/15 18:22:25 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct s_vec3
{
	float	x;
	float	y;
	float	z;
}				t_vec3;

typedef struct s_discrmn
{
	float				a;
	float				b;
	float				c;
	float				discr;
	float				res;
	t_vec3				tmp;
	t_vec3				ca;
}	t_discrmn;

/* vectors_operations.c */

t_vec3			ft_build_vector(float x, float y, float z);
float			vector_len(t_vec3 vector);
t_vec3 			vector_sum(t_vec3 first, t_vec3 second);
t_vec3			vector_sub(t_vec3 a, t_vec3 b);
float			vector_s_prod(t_vec3 a, t_vec3 b);

/* vectors_operations_2.c */

void			vector_normalize(t_vec3 *v);
t_vec3			get_norm_vector(t_vec3 *v);
t_vec3			vector_multiply(t_vec3 v, float k);
t_vec3			vec3_cross_product(t_vec3 a, t_vec3 b);
// float			vec3_len2(t_vec3 v);
// double			vec3_dist(t_vec3 vec1, t_vec3 vec2);
// t_vec3			vector_mult_s(t_vec3 v, float k);

/* vectors_operations_3.c */

t_vec3			ft_reflect_vector(t_vec3 direction, t_vec3 normale);
float			ft_find_dist(t_vec3 a, t_vec3 b);

/* vectors_rotation.c */

t_vec3			ft_rotate_x(t_vec3 vector, float phi);
t_vec3			ft_rotate_y(t_vec3 vector, float phi);
t_vec3			ft_rotate_z(t_vec3 vector, float phi);

#endif
