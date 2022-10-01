/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_map_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 20:24:09 by merlich           #+#    #+#             */
/*   Updated: 2022/10/01 21:27:20 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	ft_clean_map_data(t_scene *scene)
{
	ft_ambient_lstclear(&scene->ambient);
	ft_camera_lstclear(&scene->camera);
	ft_light_lstclear(&scene->light);
	ft_figure_lstclear(&scene->figures);
}
