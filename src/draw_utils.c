/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 21:35:22 by dirony            #+#    #+#             */
/*   Updated: 2022/10/16 21:23:33 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	my_mlx_pixel_put(t_data *pic, int x, int y, int color)
{
	char	*dest;

	if (x > 0 && x < (WIN_WIDTH - M_LEFT) && y > 0 && y < (WIN_HEIGHT - M_TOP))
	{
		dest = pic->addr + (y * pic->line_len + x * (pic->bits_per_p / 8));
		*(unsigned int *)dest = color;
	}
}

void	clean_scene_data(t_scene *scene)
{
	ft_ambient_lstclear(&scene->ambient);
	ft_camera_lstclear(&scene->camera);
	ft_light_lstclear(&scene->light);
	ft_figure_lstclear(&scene->figures);
}

void	print_manual(char *file)
{
	char	*buffer;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return ;
	buffer = get_next_line(fd);
	while (buffer)
	{
		printf("%s%s%s", YELLOW_C, buffer, RESET);
		free(buffer);
		buffer = get_next_line(fd);
	}
	close(fd);
}
