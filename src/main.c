/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 19:11:04 by dirony            #+#    #+#             */
/*   Updated: 2022/10/16 21:10:07 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

t_data	*create_pic(t_scene *scene)
{
	t_data	*pic;

	pic = malloc(sizeof(t_data));
	if (NULL == pic)
		return (NULL);
	pic->mlx = mlx_init();
	pic->window = mlx_new_window(pic->mlx, WIN_WIDTH, WIN_HEIGHT, "RT");
	pic->img = mlx_new_image(pic->mlx, WIN_WIDTH, WIN_HEIGHT);
	pic->addr = mlx_get_data_addr(pic->img, &pic->bits_per_p,
			&pic->line_len, &pic->endian);
	pic->scene_ptr = scene;
	return (pic);
}

void	ft_rotate_ray(t_camera *cam, t_vec3 *direction)
{
	*direction = ft_rotate_x(*direction, cam->angle_x);
	*direction = ft_rotate_y(*direction, cam->angle_y);
	*direction = ft_rotate_z(*direction, cam->angle_z);
}

void	render(t_data *pic, t_scene *scene)
{
	int		x;
	int		y;
	int		color;
	t_vec3	ray;

	y = 0;
	while (y < WIN_HEIGHT - 1)
	{
		x = 0;
		while (x < WIN_WIDTH - 1)
		{
			color = BLACK;
			ray = ray_by_x_y(x, y, scene);
			ft_rotate_ray(scene->camera, &ray);
			color = ft_intersection(scene, &ray);
			my_mlx_pixel_put(pic, x, y, color);
			++x;
		}
		++y;
	}
}

void	mlx_run(t_scene *scene)
{
	t_data	*pic;

	pic = create_pic(scene);
	mlx_hook(pic->window, 17, 0, ft_just_exit, pic);
	mlx_hook(pic->window, 02, 1L << 0, ft_handle_buttons, pic);
	render(pic, scene);
	mlx_put_image_to_window(pic->mlx, pic->window, pic->img, M_LEFT, M_TOP);
	mlx_loop(pic->mlx);
	free(pic);
}

int	main(int argc, char **argv)
{
	t_scene	scene;

	scene = (t_scene){};
	if (ft_check_input(argc, argv) || check_map(&scene, argv[1]))
	{
		clean_scene_data(&scene);
		return (1);
	}
	scene.camera->f = get_focus_distance(&scene);
	print_manual("/Users/merlich/Desktop/new_project_dirony_branch/manual.txt");
	mlx_run(&scene);
	clean_scene_data(&scene);
	return (0);
}
