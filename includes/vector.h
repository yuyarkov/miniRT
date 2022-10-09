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
t_vec3			vector_minus(t_vec3 a, t_vec3 b);
void			vector_normalize(t_vec3 *v);
t_vec3 			vector_sum(t_vec3 first, t_vec3 second);
float			vector_scalar_product(t_vec3 a, t_vec3 b);
void			vector_stretch(t_vec3 *v, float k);
t_vec3			vec3_multiply(t_vec3 a, double b);
t_vec3			vec3_cross_product(t_vec3 a, t_vec3 b);
float			vector_len(t_vec3 vector);
float			vec3_len2(t_vec3 v);
double			vec3_dist(t_vec3 vec1, t_vec3 vec2);
t_vec3			vector_mult_s(t_vec3 v, float k);

/* vectors_rotation.c */

t_vec3			ft_rotate_x(t_vec3 vector, float phi);
t_vec3			ft_rotate_y(t_vec3 vector, float phi);
t_vec3			ft_rotate_z(t_vec3 vector, float phi);

#endif
