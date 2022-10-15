/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 17:55:40 by merlich           #+#    #+#             */
/*   Updated: 2022/10/15 19:11:28 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

typedef struct s_scene
{
	int			err_flag;

	t_list		**lights;
	t_camera	*camera;
	t_ambient	*ambient;
	t_figure	*figures;
	t_light		*light;

}				t_scene;

float	get_focus_distance(t_scene *scene);

#endif
