/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 22:28:43 by merlich           #+#    #+#             */
/*   Updated: 2022/10/09 20:23:55 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

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

void	ft_ambient_lstdelone(t_ambient *lst)
{
	if (NULL != lst)
	{
		free(lst);
	}
}

void	ft_ambient_lstclear(t_ambient **head)
{
	t_ambient	*tmp;

	while (*head)
	{
		tmp = *head;
		*head = tmp->next;
		ft_ambient_lstdelone(tmp);
	}
}
