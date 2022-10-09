/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 19:11:04 by dirony            #+#    #+#             */
/*   Updated: 2022/10/09 20:49:58 by merlich          ###   ########.fr       */
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
	pic->window = mlx_new_window(pic->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "RT");
	pic->img = mlx_new_image(pic->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	pic->addr = mlx_get_data_addr(pic->img, &pic->bits_per_p,
			&pic->line_len, &pic->endian);
	pic->scene_ptr = scene;
	return (pic);
}

void	ft_rotate_ray(t_camera *cam, t_vec3 *dir)
{
	*dir = ft_rotate_x(*dir, cam->angle_x);
	*dir = ft_rotate_y(*dir, cam->angle_y);
	*dir = ft_rotate_z(*dir, cam->angle_z);
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
			ft_rotate_ray(scene->camera, &ray);
			color = ft_intersection(scene, &ray);
			//color = ray_cast(&ray, scene, 0);
			my_mlx_pixel_put(pic, x, y, color);
			++x;
		}
		++y;
	}
	printf("done render\n");
}

void	mlx_run(t_scene *scene)
{
	t_data	*pic;

	pic = create_pic(scene);
	mlx_hook(pic->window, 17, 0, ft_just_exit, pic);  // закрытие по клику
	mlx_hook(pic->window, 02, 1L << 0, ft_handle_buttons, pic);  // Обработка кнопок (закрытие по Esc)
	render(pic, scene);
	mlx_put_image_to_window(pic->mlx, pic->window, pic->img, M_LEFT, M_TOP);
	mlx_loop(pic->mlx);
	free(pic);
}

// void	parse_scene(char *filename, t_scene *scene)
// {
// 	(void) filename;
// 	t_camera *camera;
// 	t_figure *sphere;
// 	t_figure *sphere2;


// //пока захардкодил пробные значения для сцены. есть камера и одна сфера.

// 	camera = malloc(sizeof(t_camera));
// 	// sphere = malloc(sizeof(t_figure));
// 	camera->position.x = 0;
// 	camera->position.y = 0;
// 	camera->position.z = 0;
// 	camera->orientation.x = 0;
// 	camera->orientation.y = 0; 
// 	camera->orientation.z = 1; 
// 	camera->fov = 70;
// 	// sphere->type = SPHERE;
// 	// sphere->center.x = 0;
// 	// sphere->center.y = 0;
// 	// sphere->center.z = 1700;
// 	// sphere->radius = 650;
// 	// sphere->colour = GREEN;
	
// 	scene->figures = NULL;
// 	printf("adress = %p\n", scene->figures);
// 	sphere = ft_sphere_lstnew(ft_split("sp 0,0,1700 650 0,255,0", ' '));
// 	printf("radius = %f\n", sphere->radius);

// 	sphere2 = ft_sphere_lstnew(ft_split("sp 500,-300,1200 250 255,255,0", ' '));
// 	printf("radius = %f\n", sphere2->radius);

// 	ft_figure_lstadd_back(&(scene->figures), sphere);
// 	ft_figure_lstadd_back(&(scene->figures), sphere2);
// 	printf("radius = %f\n", sphere->radius);
// 	printf("type = %d\n", scene->figures->type);
	
// 	printf("inside parse, camera fov: %d\n", camera->fov);
// 	print_vector(camera->position, "camera.center");
// 	scene->camera = camera;

// 	printf("pointer to camera: %p, fov: %d\n", scene->camera, scene->camera->fov);
// 	camera->f = get_focus_distance(scene);  // видимо, нужно добавить эту строку в парсер.
// 	printf("фокусное расстояние: %f", camera->f);
// }

int	main(int argc, char **argv)
{
	t_scene	scene;

	scene = (t_scene) {};
	printf("adress = %p\n", scene.figures);
	if (ft_check_input(argc, argv) || check_map(&scene, argv[1]))
	{
		ft_clean_map_data(&scene);
		return (1);
	}
	// parse_scene(argv[1], &scene);
	mlx_run(&scene);
	ft_clean_map_data(&scene); // очистка структуры
	return (0);
}
