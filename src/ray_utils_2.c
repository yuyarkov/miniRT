/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 22:22:59 by merlich           #+#    #+#             */
/*   Updated: 2022/09/02 22:23:01 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	ft_ray_lstdelone(t_ray *lst)
{
	if (NULL != lst)
	{
		free(lst);
	}
}

void	ft_ray_lstclear(t_ray **head)
{
	t_ray	*tmp;

	while (*head)
	{
		tmp = *head;
		*head = tmp->next;
		ft_ray_lstdelone(tmp);
	}
}
