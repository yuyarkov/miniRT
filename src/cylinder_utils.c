/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 22:14:37 by merlich           #+#    #+#             */
/*   Updated: 2022/09/04 20:23:28 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

static void	ft_set_values(t_cylinder *new, char **ptr)
{
	char		**p1;
	char		**p2;
	char		**p3;

	p1 = ft_split(ptr[1], ',');
	p2 = ft_split(ptr[2], ',');
	p3 = ft_split(ptr[5], ',');
	new->position.x = ft_atof(p1[0]);
	new->position.y = ft_atof(p1[1]);
	new->position.z = ft_atof(p1[2]);
	new->norm_vector.x = ft_atof(p2[0]);
	new->norm_vector.y = ft_atof(p2[1]);
	new->norm_vector.z = ft_atof(p2[2]);
	new->diameter = ft_atof(ptr[3]);
	new->height = ft_atof(ptr[4]);
	new->color.a = 1;
	new->color.r = ft_atoi(p3[0]);
	new->color.g = ft_atoi(p3[1]);
	new->color.b = ft_atoi(p3[2]);
	new->next = NULL;
	ft_free_split(p3);
	ft_free_split(p2);
	ft_free_split(p1);
}

t_cylinder	*ft_cylinder_lstnew(char **ptr)
{
	t_cylinder	*new;

	new = NULL;
	if (ptr)
	{
		new = malloc(sizeof(t_cylinder));
		if (NULL == new)
		{
			free(ptr);
			exit (1);
		}
		ft_set_values(new, ptr);
	}
	return (new);
}

int	ft_cylinder_lstsize(t_cylinder *head)
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

t_cylinder	*ft_cylinder_lstlast(t_cylinder *head)
{
	if (head != NULL)
	{
		while (head->next != NULL)
		{
			head = head->next;
		}
	}
	return (head);
}

void	ft_cylinder_lstadd_front(t_cylinder **head, t_cylinder *new)
{
	if (NULL != new)
	{
		new->next = *head;
		*head = new;
	}
}

void	ft_cylinder_lstadd_back(t_cylinder **head, t_cylinder *new)
{
	t_cylinder	*lst_last;

	if (NULL != new)
	{
		lst_last = ft_cylinder_lstlast(*head);
		if (lst_last == NULL)
		{
			ft_cylinder_lstadd_front(head, new);
		}
		else
		{
			lst_last->next = new;
			new->next = NULL;
		}
	}
}
