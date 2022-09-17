#ifndef LIGHT_H
# define LIGHT_H

typedef struct s_light
{
	t_vec3				origin;
	float				intensity;
	t_color				color;
	struct s_light	*next;
}						t_light;

#endif