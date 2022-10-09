/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 22:22:04 by merlich           #+#    #+#             */
/*   Updated: 2022/10/09 20:35:11 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

static void	ft_set_values(t_light *new, char **ptr)
{
	char		**p1;
	// char		**p2;

	p1 = ft_split(ptr[1], ',');
	new->origin.x = ft_atof(p1[0]);
	new->origin.y = ft_atof(p1[1]);
	new->origin.z = ft_atof(p1[2]);
	new->intensity = ft_atof(ptr[2]);
	// Bonus part
	// p2 = ft_split(ptr[3], ',');
	// new->color.a = 1;
	// new->color.r = ft_atoi(p2[0]);
	// new->color.g = ft_atoi(p2[1]);
	// new->color.b = ft_atoi(p2[2]);
	// ft_free_split(p2);
	new->next = NULL;
	ft_free_split(p1);
}

t_light	*ft_light_lstnew(char **ptr)
{
	t_light	*new;

	new = NULL;
	if (ptr)
	{
		new = malloc(sizeof(t_light));
		if (NULL == new)
			exit (1);
		ft_set_values(new, ptr);
	}
	return (new);
}

int	ft_light_lstsize(t_light *head)
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

t_light	*ft_light_lstlast(t_light *head)
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

void	ft_light_lstadd_front(t_light **head, t_light *new)
{
	if (NULL != new)
	{
		new->next = *head;
		*head = new;
	}
}
