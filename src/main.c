/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 19:11:04 by dirony            #+#    #+#             */
/*   Updated: 2022/09/25 18:24:05 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

t_data	*create_pic()
{
	t_data	*pic;

	pic = malloc(sizeof(t_data));
	if (NULL == pic)
		return (NULL);
	pic->mlx = mlx_init();
	pic->window = mlx_new_window(pic->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "test_window");
	pic->img = mlx_new_image(pic->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	pic->addr = mlx_get_data_addr(pic->img, &pic->bits_per_p,
			&pic->line_len, &pic->endian);
	
	return (pic);
}


void	render(t_data *pic, t_scene *scene)
{
	int		x;
	int		y;
	int		color;
	t_vec3	ray;

	printf("\nstarting render, pic->line_len: %d\n\n", pic->line_len);
	y = 0;
	while (y < WINDOW_HEIGHT - 1)
	{
		x = 0;
		while (x < WINDOW_WIDTH - 1)
		{
			color = BLACK;
			ray = ray_by_x_y(x, y, scene);
			color = sphere_intersect(ray, scene->spheres->center, scene->spheres->radius, scene->spheres->color);
			//color = ray_cast(&ray, scene, 0);
			my_mlx_pixel_put(pic, x, y, color);
			++x;
		}
		++y;
	}
	printf("done render\n");
}

int simple_exit(int keycode)
{
	if (keycode == 53)
	{
		exit(EXIT_SUCCESS);
	}
	return (0);
}

void	mlx_run(t_scene *scene)
{
	t_data	*pic;
                                                                                                                                                               
	pic = create_pic();
	mlx_hook(pic->window, 17, 0, simple_exit, (void *)pic->mlx); //закрытие по клику
	mlx_hook(pic->window, 02, 1L << 0, simple_exit, (void *)pic->mlx); //закрытие по Esc
	render(pic, scene);
	mlx_put_image_to_window(pic->mlx, pic->window, pic->img, M_LEFT, M_TOP);
	mlx_loop(pic->mlx);
	free(pic);
}

void	parse_scene(char *filename, t_scene *scene)
{
	(void) filename;
	t_camera *camera;
	t_sphere *sphere;
//пока захардкодил пробные значения для сцены. есть камера и одна сфера.

	camera = malloc(sizeof(t_camera));
	sphere = malloc(sizeof(t_sphere));
	camera->position.x = 0;
	camera->position.y = 0;
	camera->position.z = 0;
	camera->orientation.x = 0;
	camera->orientation.y = 0; 
	camera->orientation.z = 1; 
	camera->fov = 70;
	sphere->center.x = 0;
	sphere->center.y = 0;
	sphere->center.z = 1700;
	sphere->radius = 650;
	sphere->color = GREEN;

	scene->spheres = sphere;
	printf("inside parse, camera fov: %d\n", camera->fov);
	print_vector(camera->position, "camera.position");
	scene->camera = camera;

	printf("pointer to camera: %p, fov: %d\n", scene->camera, scene->camera->fov);
	camera->f = get_focus_distance(scene);//видимо, нужно добавить эту строку в парсер.
	printf("фокусное расстояние: %f", camera->f);
}

void	ft_clean_map_data(t_scene *scene)
{
	ft_ambient_lstclear(&scene->ambient);
	ft_camera_lstclear(&scene->camera);
	ft_light_lstclear(&scene->light);
	ft_sphere_lstclear(&scene->spheres);
	ft_plane_lstclear(&scene->planes);
	ft_cylinder_lstclear(&scene->cylinders);
}

int	main(int argc, char **argv)
{
	t_scene	scene;

	scene = (t_scene) {};
	if (ft_check_input(argc, argv) || check_map(&scene, argv[1]))
	{
		ft_clean_map_data(&scene);
		return 1;
	}
	parse_scene(argv[1], &scene);
	mlx_run(&scene);
	// ft_clean_all(); // очистка структуры
	
	return (0);
}
