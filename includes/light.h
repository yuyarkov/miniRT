#ifndef LIGHT_H
# define LIGHT_H

typedef struct s_light
{
	t_vec3				origin;
	float				intensity;
	t_color				color;
	struct s_light	*next;
}						t_light;

/* light_utils.c */

t_light		*ft_light_lstnew(char **ptr);
int			ft_light_lstsize(t_light *head);
t_light		*ft_light_lstlast(t_light *head);
void		ft_light_lstadd_front(t_light **head, t_light *new);
void		ft_light_lstadd_back(t_light **head, t_light *new);
void		ft_light_lstdelone(t_light *lst);
void		ft_light_lstclear(t_light **head);

#endif