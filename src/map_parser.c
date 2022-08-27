/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 19:04:03 by merlich           #+#    #+#             */
/*   Updated: 2022/08/21 19:50:20 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

int	check_map(char *map)
{
	int	fd;
	
	fd = open(map, O_RDONLY);
	if (fd < 0)
	{
		printf("Error!\nCannot open the file %s\n", map);
		return 1;
	}
	
	
	return 0;
}





void	ft_print_error(void)
{

}

