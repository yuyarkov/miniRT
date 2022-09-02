/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 22:14:37 by merlich           #+#    #+#             */
/*   Updated: 2022/09/02 22:31:03 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

t_cylinder	*ft_cylinder_lstnew(char *value)
{
	t_cylinder	*new;

	new = NULL;
	if (value)
	{
		new = malloc(sizeof(t_cylinder));
		if (NULL == new)
		{
			free(value);
			exit (1);
		}
		new->position.x = 0;
		new->position.y = 0;
		new->position.z = 0;
		new->norm_vector.x = 0;
		new->norm_vector.y = 0;
		new->norm_vector.z = 0;
		new->diameter = 0;
		new->height = 0;
		new->color.a = 1;
		new->color.r = 0xFF;
		new->color.g = 0xFF;
		new->color.b = 0xFF;
		new->next = NULL;
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
