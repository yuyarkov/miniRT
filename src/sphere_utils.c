/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 22:07:22 by merlich           #+#    #+#             */
/*   Updated: 2022/09/04 20:18:26 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

static void	ft_set_values(t_sphere *new, char **ptr)
{
	char		**p1;
	char		**p2;

	p1 = ft_split(ptr[1], ',');
	p2 = ft_split(ptr[3], ',');
	new->center.x = ft_atof(p1[0]);
	new->center.y = ft_atof(p1[1]);
	new->center.z = ft_atof(p1[2]);
	new->radius = ft_atof(ptr[2]);
	new->color.a = 1;
	new->color.r = ft_atoi(p2[0]);
	new->color.g = ft_atoi(p2[1]);
	new->color.b = ft_atoi(p2[2]);
	new->next = NULL;
	ft_free_split(p2);
	ft_free_split(p1);
}

t_sphere	*ft_sphere_lstnew(char **ptr)
{
	t_sphere	*new;

	new = NULL;
	if (ptr)
	{
		new = malloc(sizeof(t_sphere));
		if (NULL == new)
		{
			// ft_free_split(ptr);
			exit (1);
		}
		ft_set_values(new, ptr);
	}
	return (new);
}

int	ft_sphere_lstsize(t_sphere *head)
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

t_sphere	*ft_sphere_lstlast(t_sphere *head)
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

void	ft_sphere_lstadd_front(t_sphere **head, t_sphere *new)
{
	if (NULL != new)
	{
		new->next = *head;
		*head = new;
	}
}

void	ft_sphere_lstadd_back(t_sphere **head, t_sphere *new)
{
	t_sphere	*lst_last;

	if (NULL != new)
	{
		lst_last = ft_sphere_lstlast(*head);
		if (lst_last == NULL)
		{
			ft_sphere_lstadd_front(head, new);
		}
		else
		{
			lst_last->next = new;
			new->next = NULL;
		}
	}
}
