#ifndef COLOUR_H
# define COLOUR_H

typedef struct s_color
{
	int	a;
	int	r;
	int	g;
	int	b;
}	t_color;

int	create_argb_color(int t, int r, int g, int b);
int	get_a_color(int argb);
int	get_r_color(int argb);
int	get_g_color(int argb);
int	get_b_color(int argb);


#endif
