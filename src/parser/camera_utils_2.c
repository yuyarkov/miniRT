/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 22:25:09 by merlich           #+#    #+#             */
/*   Updated: 2022/10/09 20:24:27 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	ft_camera_lstadd_back(t_camera **head, t_camera *new)
{
	t_camera	*lst_last;

	if (NULL != new)
	{
		lst_last = ft_camera_lstlast(*head);
		if (lst_last == NULL)
		{
			ft_camera_lstadd_front(head, new);
		}
		else
		{
			lst_last->next = new;
			new->next = NULL;
		}
	}
}

void	ft_camera_lstdelone(t_camera *lst)
{
	if (NULL != lst)
	{
		free(lst);
	}
}

void	ft_camera_lstclear(t_camera **head)
{
	t_camera	*tmp;

	while (*head)
	{
		tmp = *head;
		*head = tmp->next;
		ft_camera_lstdelone(tmp);
	}
}
