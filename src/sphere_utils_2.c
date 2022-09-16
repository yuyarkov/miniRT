/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 22:09:06 by merlich           #+#    #+#             */
/*   Updated: 2022/09/02 22:09:08 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	ft_sphere_lstdelone(t_sphere *lst)
{
	if (NULL != lst)
	{
		free(lst);
	}
}

void	ft_sphere_lstclear(t_sphere **head)
{
	t_sphere	*tmp;

	while (*head)
	{
		tmp = *head;
		*head = tmp->next;
		ft_sphere_lstdelone(tmp);
	}
}
