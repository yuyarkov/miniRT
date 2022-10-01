/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figures_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 20:28:23 by merlich           #+#    #+#             */
/*   Updated: 2022/10/01 20:50:57 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

t_figure	*ft_figure_lstlast(t_figure *head)
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

void	ft_figure_lstadd_front(t_figure **head, t_figure *new)
{
	if (NULL != new)
	{
		new->next = *head;
		*head = new;
	}
}

void	ft_figure_lstadd_back(t_figure **head, t_figure *new)
{
	t_figure	*lst_last;

	if (NULL != new)
	{
		lst_last = ft_figure_lstlast(*head);
		if (lst_last == NULL)
		{
			ft_figure_lstadd_front(head, new);
		}
		else
		{
			lst_last->next = new;
			new->next = NULL;
		}
	}
}

void	ft_figure_lstdelone(t_figure *lst)
{
	if (NULL != lst)
	{
		free(lst);
	}
}

void	ft_figure_lstclear(t_figure **head)
{
	t_figure	*tmp;

	while (*head)
	{
		tmp = *head;
		*head = tmp->next;
		ft_figure_lstdelone(tmp);
	}
}
