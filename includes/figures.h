/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figures.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dirony <dirony@21-school.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 20:14:24 by merlich           #+#    #+#             */
/*   Updated: 2022/10/08 17:54:40 by dirony           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIGURES_H
# define FIGURES_H

# define SPHERE 0
# define PLANE 1
# define CYLINDER 2

typedef struct s_figure
{
	int					type;
	void				*pointer; //указатель на саму фигуру, пригодится при вызове разных функций на пересечение
	t_vec3				center;
	t_vec3				norm_vector;
	float				radius; // cylinder
	float				height;
	// float				radius; // sphere
	t_color				color;
	int					colour;
	float				albedo[6];
	struct s_figure 	*next;

}						t_figure;

/* figures_utils_1.c */

t_figure	*ft_sphere_lstnew(char **ptr);
t_figure	*ft_plane_lstnew(char **ptr);
t_figure	*ft_cylinder_lstnew(char **ptr);
int			ft_figure_lstsize(t_figure *head);

/* figures_utils_2.c */

t_figure	*ft_figure_lstlast(t_figure *head);
void		ft_figure_lstadd_front(t_figure **head, t_figure *new);
void		ft_figure_lstadd_back(t_figure **head, t_figure *new);
void		ft_figure_lstdelone(t_figure *lst);
void		ft_figure_lstclear(t_figure **head);

/* sphere_utils.c */

// t_figure	*sphere_create(t_vec3 center, float radius);
// t_vec3		sphere_get_normal(t_vec3 point, t_figure sphere);


#endif
