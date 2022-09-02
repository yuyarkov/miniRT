/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 21:45:59 by merlich           #+#    #+#             */
/*   Updated: 2022/09/02 22:31:40 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

t_plane	*ft_plane_lstnew(char *value)
{
	t_plane	*new;

	new = NULL;
	if (value)
	{
		new = malloc(sizeof(t_plane));
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
		new->color.a = 1;
		new->color.r = 0xFF;
		new->color.g = 0xFF;
		new->color.b = 0xFF;
		new->next = NULL;
	}
	return (new);
}

int	ft_plane_lstsize(t_plane *head)
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

t_plane	*ft_plane_lstlast(t_plane *head)
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

void	ft_plane_lstadd_front(t_plane **head, t_plane *new)
{
	if (NULL != new)
	{
		new->next = *head;
		*head = new;
	}
}

void	ft_plane_lstadd_back(t_plane **head, t_plane *new)
{
	t_plane	*lst_last;

	if (NULL != new)
	{
		lst_last = ft_plane_lstlast(*head);
		if (lst_last == NULL)
		{
			ft_plane_lstadd_front(head, new);
		}
		else
		{
			lst_last->next = new;
			new->next = NULL;
		}
	}
}
