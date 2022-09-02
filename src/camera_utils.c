/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 22:25:03 by merlich           #+#    #+#             */
/*   Updated: 2022/09/02 22:26:29 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

t_camera	*ft_camera_lstnew(char *value)
{
	t_camera	*new;

	new = NULL;
	if (value)
	{
		new = malloc(sizeof(t_camera));
		if (NULL == new)
		{
			free(value);
			exit (1);
		}
		new->position.x = 0;
		new->position.y = 0;
		new->position.z = 0;
		new->orientation.x = 0;
		new->orientation.y = 0;
		new->orientation.z = 0;
		new->fov = 70;
		new->next = NULL;
	}
	return (new);
}

int	ft_camera_lstsize(t_camera *head)
{
	int	count;

	count = 0;
	while (head)
	{
		head = head->next;
		count++;
	}
	return (count);
}

t_camera	*ft_camera_lstlast(t_camera *head)
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

void	ft_camera_lstadd_front(t_camera **head, t_camera *new)
{
	if (NULL != new)
	{
		new->next = *head;
		*head = new;
	}
}

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
