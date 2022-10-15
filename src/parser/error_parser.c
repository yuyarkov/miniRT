/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 18:12:02 by merlich           #+#    #+#             */
/*   Updated: 2022/10/15 21:38:43 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

static int	ft_print_msg(void)
{
	printf("%s---------------------------\n%s", RED_C, RESET);
	printf("%sError!\nBad arguments.%s\n", RED_C, RESET);
	printf("%sExample: ./miniRT map.rt%s\n", YELLOW_C, RESET);
	printf("%s---------------------------\n%s", RED_C, RESET);
	return (1);
}

int	ft_check_input(int argc, char **argv)
{
	char	*ptr;

	ptr = NULL;
	if (argc != 2)
		return (ft_print_msg());
	else
	{
		ptr = ft_strrchr(argv[1], '.');
		if (!ptr || ft_strncmp(ptr, ".rt", 4))
			return (ft_print_msg());
	}
	return (0);
}
