#ifndef SCENE_H
# define SCENE_H

// typedef struct s_scene
// {
// 	t_sphere    *spheres;
//     t_list		**objects;
// 	t_list		**lights;
// 	t_camera	*camera;
// 	//t_ambient	*ambient;
// }				t_scene;

typedef struct s_scene
{
	int			err_flag;

	t_list		**lights;
	t_camera	*camera;
	t_ambient	*ambient;


	/* Указатели на голову списков */
	t_plane		*planes;
	t_sphere	*spheres;
	t_cylinder	*cylinders;

	// t_camera	*camera;
	t_light		*light;
	// t_ambient	*ambient;

	/* Итераторы */
	t_plane		*planes_head;
	t_sphere	*spheres_head;
	t_cylinder	*cylinders_head;

	t_camera	*camera_head;
	t_light		*light_head;
	t_ambient	*ambient_head;

}				t_scene;

float 			get_focus_distance(t_scene *scene);

#endif