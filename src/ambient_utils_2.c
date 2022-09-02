/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 22:28:43 by merlich           #+#    #+#             */
/*   Updated: 2022/09/02 22:30:42 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

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
