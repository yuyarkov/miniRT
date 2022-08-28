/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dirony <dirony@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 19:11:04 by dirony            #+#    #+#             */
/*   Updated: 2021/12/11 18:16:37 by dirony           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_data	*create_pic(t_map_data *map_data)
{
	t_data	*pic;

(void) map_data;
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

void	mlx_run(t_dot **map, t_map_data *map_data)
{
	t_data	*pic;
	t_pixel pixel1;
	t_pixel pixel2;

	map_data->map = map;
	pic = create_pic(map_data);
	map_data->pic = pic;
	// mlx_hook(mlx->win_ptr, 17, 0, crossclose, (void *)mlx); //закрытие по клику
	// mlx_hook(mlx->win_ptr, 02, 1L << 0, esc_key, (void *)mlx); //закрытие по Esc
	pixel1.x = 50;
	pixel1.y = 50;
	pixel1.color = WHITE;
	pixel2.x = 150;
	pixel2.y = 150;
	pixel2.color = WHITE;


	draw_line(pixel1, pixel2, pic);
	render(map_data->pic, NULL);
	mlx_put_image_to_window(pic->mlx, pic->window, pic->img, M_LEFT, M_TOP);
	mlx_loop(pic->mlx);
	free(pic);
}


void	*clear_map(t_dot **map, int i)
{
	while (i - 1)
	{
		free(map[i - 1]);
		i--;
	}
	free(map[0]);
	free(map);
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_dot		**map;
	t_map_data	*map_data;

(void) argc;
(void) argv;
	printf("\n      hello\n");
	// if (argc < 1)
	// 	return (0);
	map_data = malloc(sizeof(t_map_data));
	if (NULL == map_data)
		return (0);
	//map = parse_map(argv[1], map_data);
	map = NULL;
	// if (!map)
	// {
	// 	free(map_data);
	// 	return (0);
	// }
	mlx_run(map, map_data);
	return (0);
}
