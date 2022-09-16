/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_utils copy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 22:01:45 by merlich           #+#    #+#             */
/*   Updated: 2022/09/02 22:02:55 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	ft_plane_lstdelone(t_plane *lst)
{
	if (NULL != lst)
	{
		free(lst);
	}
}

void	ft_plane_lstclear(t_plane **head)
{
	t_plane	*tmp;

	while (*head)
	{
		tmp = *head;
		*head = tmp->next;
		ft_plane_lstdelone(tmp);
	}
}
