/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figures_utils_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 20:27:27 by merlich           #+#    #+#             */
/*   Updated: 2022/10/15 22:04:51 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

t_figure	*ft_figure_lstnew(void)
{
	t_figure	*new;

	new = malloc(sizeof(t_figure));
	if (NULL == new)
		exit (1);
	*new = (t_figure){};
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
	ft_fill_center(&new->center, p1);
	new->radius = ft_atof(ptr[2]);
	ft_fill_color(&new->color, &new->colour, p2);
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
	ft_fill_center(&new->center, p1);
	ft_fill_norm_vector(&new->norm_vector, p2);
	ft_fill_color(&new->color, &new->colour, p3);
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
	ft_fill_center(&new->center, p1);
	ft_fill_norm_vector(&new->norm_vector, p2);
	new->radius = ft_atof(ptr[3]);
	new->height = ft_atof(ptr[4]);
	ft_fill_color(&new->color, &new->colour, p3);
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
