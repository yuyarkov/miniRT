/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 19:04:03 by merlich           #+#    #+#             */
/*   Updated: 2022/10/09 20:33:56 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

static int	ft_perror(char *msg)
{
	printf(msg);
	return (1);
}

static int	ft_check_doubles(t_scene *scene)
{
	if (ft_ambient_lstsize(scene->ambient) != 1)
		return (ft_perror("There must be ONE ambient lightning source\
		in the map!\n"));
	else if (ft_camera_lstsize(scene->camera) != 1)
		return (ft_perror("There must be ONE camera in the map!\n"));
	else if (ft_light_lstsize(scene->light) != 1)
		return (ft_perror("There must be ONE lightning source in the map!\n"));
	return (0);
}

static int	ft_fill_list(t_scene *scene, char **ptr)
{
	if (ptr && ptr[0] && ft_strcmp(ptr[0], "\n"))
	{
		if (!ft_strcmp(ptr[0], "A") && !ft_check_params_a(ptr))
			ft_ambient_lstadd_back(&(scene->ambient), ft_ambient_lstnew(ptr));
		else if (!ft_strcmp(ptr[0], "C") && !ft_check_params_c(ptr))
			ft_camera_lstadd_back(&(scene->camera), ft_camera_lstnew(ptr));
		else if (!ft_strcmp(ptr[0], "L") && !ft_check_params_l(ptr))
			ft_light_lstadd_back(&(scene->light), ft_light_lstnew(ptr));
		else if (!ft_strcmp(ptr[0], "sp") && !ft_check_params_sp(ptr))
			ft_figure_lstadd_back(&(scene->figures), ft_sphere_lstnew(ptr));
		else if (!ft_strcmp(ptr[0], "cy") && !ft_check_params_cy(ptr))
			ft_figure_lstadd_back(&(scene->figures), ft_cylinder_lstnew(ptr));
		else if (!ft_strcmp(ptr[0], "pl") && !ft_check_params_pl(ptr))
			ft_figure_lstadd_back(&(scene->figures), ft_plane_lstnew(ptr));
		else
			return (ft_perror("MAP ERROR\n"));
	}
	return (0);
}

int	check_map(t_scene *scene, char *map)
{
	int		fd;
	int		err;
	char	*str;
	char	**ptr;

	err = 0;
	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (ft_perror("Error!\nCannot open the file!\n"));
	str = get_next_line(fd);
	while (str)
	{
		ptr = ft_split(str, ' ');
		err = ft_fill_list(scene, ptr);
		ft_free_split(ptr);
		free(str);
		if (err)
			break ;
		str = get_next_line(fd);
	}
	close(fd);
	printf("pointer to camera: %p, fov: %d\n", scene->camera, scene->camera->fov);
	scene->camera->f = get_focus_distance(scene);
	printf("фокусное расстояние: %f", scene->camera->f);
	if (ft_check_doubles(scene) || err)
		return (1);
	return (0);
}
