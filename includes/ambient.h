#ifndef AMBIENT_H
# define AMBIENT_H

typedef struct s_ambient
{
	float				intensity;
	t_color				color;
	struct s_ambient	*next;
}						t_ambient;

#endif