/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 22:07:22 by merlich           #+#    #+#             */
/*   Updated: 2022/09/02 22:31:54 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

t_sphere	*ft_sphere_lstnew(char *value)
{
	t_sphere	*new;

	new = NULL;
	if (value)
	{
		new = malloc(sizeof(t_sphere));
		if (NULL == new)
		{
			free(value);
			exit (1);
		}
		new->center.x = 0;
		new->center.y = 0;
		new->center.z = 0;
		new->radius = 0;
		new->color = 0xFF;
		// new->color.a = 1;
		// new->color.r = 0xFF;
		// new->color.g = 0xFF;
		// new->color.b = 0xFF;
		new->next = NULL;
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
