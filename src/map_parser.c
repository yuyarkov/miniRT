/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 19:04:03 by merlich           #+#    #+#             */
/*   Updated: 2022/09/04 21:07:27 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

static int	ft_print_error(void)
{
	// some code here
	printf("MAP ERROR!");
	return 0;
}

int	check_map(t_scene *scene, char *map)
{
	int		fd;
	char	*str;
	char	**ptr;

	fd = open(map, O_RDONLY);
	if (fd < 0)
	{
		printf("Error!\nCannot open the file %s\n", map);
		return 1;
	}
	
	str = get_next_line(fd);
	while (str)
	{
		ptr = ft_split(str, ' ');
		ft_fill_list(scene, ptr);
		ft_free_split(ptr);
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	if (ft_check_doubles(scene))
		return 1;
	return 0;
}

static int	ft_check_doubles(t_scene *scene)
{
	if (ft_ambient_lstsize(scene->ambient) != 1)
	{
		printf("There could be only one ambient lightning source");
		return 1;
	}
	else if (ft_camera_lstsize(scene->camera) != 1)
	{
		printf("There could be only one camera");
		return 1;
	}
	else if (ft_light_lstsize(scene->light) != 1)
	{
		printf("There could be only one lightning source");
		return 1;
	}
	return 0;
}

static void	ft_fill_list(t_scene *scene, char **ptr)
{
	if (ptr)
	{
		if (!ft_strcmp(ptr[0], "A") /* && ft_chek_params(...) */)
		{
			ft_ambient_lstadd_back(&scene->ambient, ft_ambient_lstnew(ptr));
		}
		else if (!ft_strcmp(ptr[0], "C"))
		{
			ft_camera_lstadd_back(&scene->ambient, ft_ambient_lstnew(ptr));
		}
		else if (!ft_strcmp(ptr[0], "L"))
		{
			ft_ray_lstadd_back(&scene->ambient, ft_ambient_lstnew(ptr));
		}
		else if (!ft_strcmp(ptr[0], "sp"))
		{
			ft_sphere_lstadd_back(&scene->ambient, ft_ambient_lstnew(ptr));
		}
		else if (!ft_strcmp(ptr[0], "cy"))
		{
			ft_cylinder_lstadd_back(&scene->ambient, ft_ambient_lstnew(ptr));
		}
		else if (!ft_strcmp(ptr[0], "pl"))
		{
			ft_plane_lstadd_back(&scene->ambient, ft_ambient_lstnew(ptr));
		}
		else
		{
			return ft_print_error();
		}
	}
}



