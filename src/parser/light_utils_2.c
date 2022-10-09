/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 22:22:59 by merlich           #+#    #+#             */
/*   Updated: 2022/10/09 20:34:26 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	ft_light_lstadd_back(t_light **head, t_light *new)
{
	t_light	*lst_last;

	if (NULL != new)
	{
		lst_last = ft_light_lstlast(*head);
		if (lst_last == NULL)
		{
			ft_light_lstadd_front(head, new);
		}
		else
		{
			lst_last->next = new;
			new->next = NULL;
		}
	}
}

void	ft_light_lstdelone(t_light *lst)
{
	if (NULL != lst)
	{
		free(lst);
	}
}

void	ft_light_lstclear(t_light **head)
{
	t_light	*tmp;

	while (*head)
	{
		tmp = *head;
		*head = tmp->next;
		ft_light_lstdelone(tmp);
	}
}
