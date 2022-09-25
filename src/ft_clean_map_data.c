/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_map_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 20:24:09 by merlich           #+#    #+#             */
/*   Updated: 2022/09/25 20:24:32 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	ft_clean_map_data(t_scene *scene)
{
	ft_ambient_lstclear(&scene->ambient);
	ft_camera_lstclear(&scene->camera);
	ft_light_lstclear(&scene->light);
	ft_sphere_lstclear(&scene->spheres);
	ft_plane_lstclear(&scene->planes);
	ft_cylinder_lstclear(&scene->cylinders);
}
