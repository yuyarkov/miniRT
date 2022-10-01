#ifndef AMBIENT_H
# define AMBIENT_H

typedef struct s_ambient
{
	float				intensity;
	t_color				color;
	struct s_ambient	*next;
}						t_ambient;

/* ambient_utils.c */

t_ambient	*ft_ambient_lstnew(char **ptr);
int			ft_ambient_lstsize(t_ambient *head);
t_ambient	*ft_ambient_lstlast(t_ambient *head);
void		ft_ambient_lstadd_front(t_ambient **head, t_ambient *new);
void		ft_ambient_lstadd_back(t_ambient **head, t_ambient *new);
void		ft_ambient_lstdelone(t_ambient *lst);
void		ft_ambient_lstclear(t_ambient **head);

#endif
