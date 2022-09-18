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

#endif