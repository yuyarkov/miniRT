#ifndef CAMERA_H
# define CAMERA_H


typedef struct s_camera
{
	t_vec3			position;
	t_vec3			orientation;
	int				fov;
	float			f;//фокусное расстояние
	struct s_camera	*next;
}					t_camera;


t_camera		*camera_create(t_vec3 pos, t_vec3 rot, int fov);

/* camera_utils.c */

t_camera	*ft_camera_lstnew(char **ptr);
int			ft_camera_lstsize(t_camera *head);
t_camera	*ft_camera_lstlast(t_camera *head);
void		ft_camera_lstadd_front(t_camera **head, t_camera *new);
void		ft_camera_lstadd_back(t_camera **head, t_camera *new);
void		ft_camera_lstdelone(t_camera *lst);
void		ft_camera_lstclear(t_camera **head);

#endif
