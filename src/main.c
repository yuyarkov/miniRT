/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 19:11:04 by dirony            #+#    #+#             */
/*   Updated: 2022/09/02 19:56:19 by merlich          ###   ########.fr       */
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
	t_ray	ray;

(void) scene;
(void) ray;
	printf("\nstarting render, pic->line_len: %d\n\n", pic->line_len);
	y = 0;
	while (y < WINDOW_HEIGHT - 1)
	{
		x = 0;
		while (x < WINDOW_WIDTH - 1)
		{
			color = GREEN;
			//ray = ray_from_camera(x, y, scene->camera);
			//color = ray_cast(&ray, scene, 0);
			my_mlx_pixel_put(pic, x, y, color);
			++x;
		}
		++y;
	}
	printf("done render\n");
}

int simple_exit()
{
	exit(EXIT_SUCCESS);
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


// void	*clear_map(t_dot **map, int i)
// {
// 	while (i - 1)
// 	{
// 		free(map[i - 1]);
// 		i--;
// 	}
// 	free(map[0]);
// 	free(map);
// 	return (NULL);
// }

void	parse_scene(char *filename, t_scene *scene)
{
	(void) filename;
	t_camera camera;
	t_sphere sphere;
//пока захардкодил пробные значения для сцены. есть камера и одна сфера.
	camera.position.x = -50;
	camera.position.y = 0;
	camera.position.z = 20;
	camera.orientation.x = 0;
	camera.orientation.y = 0; 
	camera.orientation.z = 1; 
	camera.fov = 70;

	sphere.center.x = 0;
	sphere.center.x = 0;
	sphere.center.x = 20.6;
	sphere.radius = 12.6;
	sphere.color = WHITE;

	scene->spheres = &sphere;
	scene->camera = &camera;
}

int	main(int argc, char **argv)
{
	t_scene	scene;

	if (ft_check_input(argc, argv) || check_map(argv[1]))
		return 1;
	parse_scene(argv[1], &scene);
	mlx_run(&scene);
	return (0);
}
