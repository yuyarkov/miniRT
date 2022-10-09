#ifndef COLOUR_H
# define COLOUR_H

typedef struct s_color
{
	int	a;
	int	r;
	int	g;
	int	b;
}	t_color;

/* color_utils_1.c */

int	create_argb_color(int t, int r, int g, int b);
int	get_a_color(int argb);
int	get_r_color(int argb);
int	get_g_color(int argb);
int	get_b_color(int argb);

/* color_utils_2.c */

int	ft_rgb(int color, char level);
int	ft_mul_clr(t_color clr, float ratio);
int	ft_add_clr(int color, int coef);
int	ft_add_clr3(int c1, int c2, int c3);

#endif
