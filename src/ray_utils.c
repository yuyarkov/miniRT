/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 22:22:04 by merlich           #+#    #+#             */
/*   Updated: 2022/09/02 22:22:44 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

t_ray	*ft_ray_lstnew(char *value)
{
	t_ray	*new;

	new = NULL;
	if (value)
	{
		new = malloc(sizeof(t_ray));
		if (NULL == new)
		{
			free(value);
			exit (1);
		}
		new->origin.x = 0;
		new->origin.y = 0;
		new->origin.z = 0;
		new->direction.x = 0;
		new->direction.y = 0;
		new->direction.z = 0;
		new->next = NULL;
	}
	return (new);
}

int	ft_ray_lstsize(t_ray *head)
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

t_ray	*ft_ray_lstlast(t_ray *head)
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

void	ft_ray_lstadd_front(t_ray **head, t_ray *new)
{
	if (NULL != new)
	{
		new->next = *head;
		*head = new;
	}
}

void	ft_ray_lstadd_back(t_ray **head, t_ray *new)
{
	t_ray	*lst_last;

	if (NULL != new)
	{
		lst_last = ft_ray_lstlast(*head);
		if (lst_last == NULL)
		{
			ft_ray_lstadd_front(head, new);
		}
		else
		{
			lst_last->next = new;
			new->next = NULL;
		}
	}
}
