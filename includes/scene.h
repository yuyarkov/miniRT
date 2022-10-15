/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 17:55:40 by merlich           #+#    #+#             */
/*   Updated: 2022/10/15 17:55:41 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	t_figure	*figures;

	// t_camera	*camera;
	t_light		*light;

	/* Итераторы */
	t_figure	*figures_head;

	t_camera	*camera_head;
	t_light		*light_head;
	t_ambient	*ambient_head;

}				t_scene;

float 			get_focus_distance(t_scene *scene);

#endif
