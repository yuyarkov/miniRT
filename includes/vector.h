#ifndef VECTOR_H
# define VECTOR_H

// typedef struct s_vec3
// {
// 	float	x;
// 	float	y;
// 	float	z;
// }				t_vec3;

t_vec3			vec3_create(float x, float y, float z);
t_vec3			vector_minus(t_vec3 a, t_vec3 b);
void			vector_normalize(t_vec3 *v);
t_vec3			vec3_add(t_vec3 a, t_vec3 b);
float			vector_dot_product(t_vec3 a, t_vec3 b);
t_vec3			vec3_multiply(t_vec3 a, double b);
t_vec3			vec3_cross_product(t_vec3 a, t_vec3 b);
float			vec3_len(t_vec3 vector);
float			vec3_len2(t_vec3 v);
double			vec3_dist(t_vec3 vec1, t_vec3 vec2);

#endif