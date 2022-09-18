#ifndef PLANE_H
# define PLANE_H

typedef struct s_plane
{
	t_vec3				position;
	t_vec3				norm_vector;
	t_color				color;
	struct s_plane		*next;
}						t_plane;

/* plane_utils.c */

t_plane	*ft_plane_lstnew(char **ptr);
int		ft_plane_lstsize(t_plane *head);
t_plane	*ft_plane_lstlast(t_plane *head);
void	ft_plane_lstadd_front(t_plane **head, t_plane *new);
void	ft_plane_lstadd_back(t_plane **head, t_plane *new);
void	ft_plane_lstdelone(t_plane *lst);
void	ft_plane_lstclear(t_plane **head);

#endif