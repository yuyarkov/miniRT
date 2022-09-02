/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 22:15:06 by merlich           #+#    #+#             */
/*   Updated: 2022/09/02 22:15:08 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	ft_cylinder_lstdelone(t_cylinder *lst)
{
	if (NULL != lst)
	{
		free(lst);
	}
}

void	ft_cylinder_lstclear(t_cylinder **head)
{
	t_cylinder	*tmp;

	while (*head)
	{
		tmp = *head;
		*head = tmp->next;
		ft_cylinder_lstdelone(tmp);
	}
}
