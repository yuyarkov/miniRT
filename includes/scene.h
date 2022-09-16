#ifndef SCENE_H
# define SCENE_H

typedef struct s_scene
{
	t_sphere    *spheres;
    t_list		**objects;
	t_list		**lights;
	t_camera	*camera;
	//t_ambient	*ambient;
}				t_scene;

float 			get_focus_distance(t_scene *scene);

#endif