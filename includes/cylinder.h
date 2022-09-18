#ifndef CYLINDER_H
# define CYLINDER_H

typedef struct s_cylinder
{
	t_vec3				position;
	t_vec3				norm_vector;
	float				diameter;
	float				height;
	t_color				color;
	struct s_cylinder	*next;
}						t_cylinder;

/* cylinder_utils.c */

t_cylinder	*ft_cylinder_lstnew(char **ptr);
int			ft_cylinder_lstsize(t_cylinder *head);
t_cylinder	*ft_cylinder_lstlast(t_cylinder *head);
void		ft_cylinder_lstadd_front(t_cylinder **head, t_cylinder *new);
void		ft_cylinder_lstadd_back(t_cylinder **head, t_cylinder *new);
void		ft_cylinder_lstdelone(t_cylinder *lst);
void		ft_cylinder_lstclear(t_cylinder **head);

#endif