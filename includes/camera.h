/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dirony <dirony@21-school.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 17:55:59 by merlich           #+#    #+#             */
/*   Updated: 2022/10/16 18:25:19 by dirony           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

typedef struct s_camera
{
	t_vec3			position;
	t_vec3			orientation;
	int				fov;
	float			f;
	float			angle_x;
	float			angle_y;
	float			angle_z;
	struct s_camera	*next;
}					t_camera;

/* camera_utils.c */

t_camera	*ft_camera_lstnew(char **ptr);
int			ft_camera_lstsize(t_camera *head);
t_camera	*ft_camera_lstlast(t_camera *head);
void		ft_camera_lstadd_front(t_camera **head, t_camera *new);
void		ft_camera_lstadd_back(t_camera **head, t_camera *new);
void		ft_camera_lstdelone(t_camera *lst);
void		ft_camera_lstclear(t_camera **head);

#endif
