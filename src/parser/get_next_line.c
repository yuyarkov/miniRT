/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:16:50 by merlich           #+#    #+#             */
/*   Updated: 2022/10/09 20:30:47 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

static size_t	ft_search(char *s, char c)
{
	size_t	ind;
	size_t	len;

	ind = 0;
	len = ft_strlen(s);
	while ((ind < len) && ((unsigned char) s[ind] != (unsigned char) c))
	{
		ind++;
	}
	return (ind);
}

static char	*ft_get_new_tmp(char *tmp, char *buff)
{
	char	*tmp_old;

	tmp_old = tmp;
	tmp = ft_strjoin(tmp, buff);
	free(tmp_old);
	return (tmp);
}

static char	*ft_build_line(char *s, char *tmp, char *buff)
{
	int		index;
	char	*str;
	char	*line;

	index = ft_search(tmp, '\n');
	str = ft_substr(tmp, 0, index + 1);
	line = ft_strjoin(s, str);
	free(str);
	ft_str_dup(ft_strchr(buff, '\n'), s);
	free(buff);
	free(tmp);
	return (line);
}

static char	*ft_get_line(int fd, char *s, char *buff, char *tmp)
{
	int	res;

	res = read(fd, buff, BUFFER_SIZE);
	if (res == -1 || (res == 0 && s[0] == '\0'))
	{
		free(tmp);
		free(buff);
		return (NULL);
	}
	buff[res] = '\0';
	while ((ft_search(buff, '\n') == ft_strlen(buff)) && (res > 0))
	{
		tmp = ft_get_new_tmp(tmp, buff);
		res = read(fd, buff, BUFFER_SIZE);
		if (res == -1)
		{
			free(tmp);
			free(buff);
			return (NULL);
		}
		buff[res] = '\0';
	}
	tmp = ft_get_new_tmp(tmp, buff);
	return (ft_build_line(s, tmp, buff));
}

char	*get_next_line(int fd)
{
	static char	s[OPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	char		*tmp;
	char		*buff;

	line = NULL;
	if (fd < 0)
		return (NULL);
	if ((ft_search(s[fd], '\n') != ft_strlen(s[fd])))
	{
		line = ft_substr(s[fd], 0, ft_search(s[fd], '\n') + 1);
		ft_str_dup(ft_strchr(s[fd], '\n'), s[fd]);
		return (line);
	}
	tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (NULL == tmp)
		return (NULL);
	tmp[0] = '\0';
	buff = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (NULL == buff)
		return (NULL);
	buff[0] = '\0';
	line = ft_get_line(fd, s[fd], buff, tmp);
	return (line);
}
