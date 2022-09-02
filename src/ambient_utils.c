/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 22:28:48 by merlich           #+#    #+#             */
/*   Updated: 2022/09/02 22:31:13 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

t_ambient	*ft_ambient_lstnew(char *value)
{
	t_ambient	*new;

	new = NULL;
	if (value)
	{
		new = malloc(sizeof(t_ambient));
		if (NULL == new)
		{
			free(value);
			exit (1);
		}
		new->color.a = 0xFF;
		new->color.r = 0xFF;
		new->color.g = 0xFF;
		new->color.b = 0xFF;
		new->intensity = 1;
		new->next = NULL;
	}
	return (new);
}

int	ft_ambient_lstsize(t_ambient *head)
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

t_ambient	*ft_ambient_lstlast(t_ambient *head)
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

void	ft_ambient_lstadd_front(t_ambient **head, t_ambient *new)
{
	if (NULL != new)
	{
		new->next = *head;
		*head = new;
	}
}

void	ft_ambient_lstadd_back(t_ambient **head, t_ambient *new)
{
	t_ambient	*lst_last;

	if (NULL != new)
	{
		lst_last = ft_ambient_lstlast(*head);
		if (lst_last == NULL)
		{
			ft_ambient_lstadd_front(head, new);
		}
		else
		{
			lst_last->next = new;
			new->next = NULL;
		}
	}
}
