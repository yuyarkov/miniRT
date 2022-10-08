/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figures_utils_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dirony <dirony@21-school.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 20:27:27 by merlich           #+#    #+#             */
/*   Updated: 2022/10/08 17:50:26 by dirony           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/miniRT.h"

t_figure	*ft_figure_lstnew(void)
{
	t_figure	*new;

	new = malloc(sizeof(t_figure));
	if (NULL == new)
		exit (1);
	*new = (t_figure) {};
	return (new);
}

t_figure	*ft_sphere_lstnew(char **ptr)
{
	t_figure	*new;
	char		**p1;
	char		**p2;

	new = ft_figure_lstnew();
	p1 = ft_split(ptr[1], ',');
	p2 = ft_split(ptr[3], ',');
	new->type = SPHERE;
	new->center.x = ft_atof(p1[0]);
	new->center.y = ft_atof(p1[1]);
	new->center.z = ft_atof(p1[2]);
	new->radius = ft_atof(ptr[2]);
	new->color.t = 1;
	new->color.r = ft_atoi(p2[0]);
	new->color.g = ft_atoi(p2[1]);
	new->color.b = ft_atoi(p2[2]);
	new->colour = create_argb_color(new->color.t, new->color.r, new->color.g, new->color.b);
	new->next = NULL;
	ft_free_split(p2);
	ft_free_split(p1);
	return (new);
}

t_figure	*ft_plane_lstnew(char **ptr)
{
	t_figure	*new;
	char		**p1;
	char		**p2;
	char		**p3;

	new = ft_figure_lstnew();
	p1 = ft_split(ptr[1], ',');
	p2 = ft_split(ptr[2], ',');
	p3 = ft_split(ptr[3], ',');
	new->type = PLANE;
	new->center.x = ft_atof(p1[0]);
	new->center.y = ft_atof(p1[1]);
	new->center.z = ft_atof(p1[2]);
	new->norm_vector.x = ft_atof(p2[0]);
	new->norm_vector.y = ft_atof(p2[1]);
	new->norm_vector.z = ft_atof(p2[2]);
	new->color.t = 1;
	new->color.r = ft_atoi(p3[0]);
	new->color.g = ft_atoi(p3[1]);
	new->color.b = ft_atoi(p3[2]);
	new->colour = create_argb_color(new->color.t, new->color.r, new->color.g, new->color.b);
	new->next = NULL;
	ft_free_split(p3);
	ft_free_split(p2);
	ft_free_split(p1);
	return (new);
}

t_figure	*ft_cylinder_lstnew(char **ptr)
{
	t_figure	*new;
	char		**p1;
	char		**p2;
	char		**p3;

	new = ft_figure_lstnew();
	p1 = ft_split(ptr[1], ',');
	p2 = ft_split(ptr[2], ',');
	p3 = ft_split(ptr[5], ',');
	new->type = CYLINDER;
	new->center.x = ft_atof(p1[0]);
	new->center.y = ft_atof(p1[1]);
	new->center.z = ft_atof(p1[2]);
	new->norm_vector.x = ft_atof(p2[0]);
	new->norm_vector.y = ft_atof(p2[1]);
	new->norm_vector.z = ft_atof(p2[2]);
	new->radius = ft_atof(ptr[3]);
	new->height = ft_atof(ptr[4]);
	new->color.t = 1;
	new->color.r = ft_atoi(p3[0]);
	new->color.g = ft_atoi(p3[1]);
	new->color.b = ft_atoi(p3[2]);
	new->colour = create_argb_color(new->color.t, new->color.r, new->color.g, new->color.b);
	new->next = NULL;
	ft_free_split(p3);
	ft_free_split(p2);
	ft_free_split(p1);
	return (new);
}

int	ft_figure_lstsize(t_figure *head)
{
	int	count;

	count = 0;
	while (head)
	{
		head = head->next;
		count++;
	}
	return (count);
}
