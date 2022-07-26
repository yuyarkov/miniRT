/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 22:28:48 by merlich           #+#    #+#             */
/*   Updated: 2022/09/04 20:05:43 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

static void	ft_set_values(t_ambient *new, char **ptr)
{
	char		**p;

	p = ft_split(ptr[2], ',');
	
	new->intensity = ft_atof(ptr[1]);
	new->color.a = 1;
	new->color.r = ft_atoi(p[0]);
	new->color.g = ft_atoi(p[1]);
	new->color.b = ft_atoi(p[2]);
	new->next = NULL;
	ft_free_split(p);
}

t_ambient	*ft_ambient_lstnew(char **ptr)
{
	t_ambient	*new;

	new = NULL;
	if (ptr)
	{
		new = malloc(sizeof(t_ambient));
		if (NULL == new)
		{
			// ft_free_split(ptr);
			exit (1);
		}
		ft_set_values(new, ptr);
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
