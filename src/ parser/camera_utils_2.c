/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 22:25:09 by merlich           #+#    #+#             */
/*   Updated: 2022/09/02 22:25:26 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

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
