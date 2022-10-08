/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_utils_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 22:25:03 by merlich           #+#    #+#             */
/*   Updated: 2022/10/08 18:55:46 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

static void	ft_set_values(t_camera *new, char **ptr)
{
	char		**p1;
	char		**p2;

	p1 = ft_split(ptr[1], ',');
	p2 = ft_split(ptr[2], ',');
	new->position.x = ft_atof(p1[0]);
	new->position.y = ft_atof(p1[1]);
	new->position.z = ft_atof(p1[2]);
	new->orientation.x = ft_atof(p2[0]);
	new->orientation.y = ft_atof(p2[1]);
	new->orientation.z = ft_atof(p2[2]);
	new->fov = ft_atof(ptr[3]);
	new->angle_y = 0;
	new->angle_z = 0;
	new->next = NULL;
	ft_free_split(p2);
	ft_free_split(p1);
}

t_camera	*ft_camera_lstnew(char **ptr)
{
	t_camera	*new;

	new = NULL;
	if (ptr)
	{
		new = malloc(sizeof(t_camera));
		if (NULL == new)
		{
			// ft_free_split(ptr);
			exit (1);
		}
		ft_set_values(new, ptr);
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
