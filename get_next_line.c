/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:00:18 by sokaraku          #+#    #+#             */
/*   Updated: 2023/12/01 17:26:10 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	store_in_line(char **keep, char **line) // bytes_read?
{
	if (ft_check(*keep, '\n'))
	{
		*line = (char *)malloc(sizeof(char) * ft_check(*keep, '\n') + 2);
		//+2car ft check retourne lindice
		if (!(*line))
			return ;
		ft_memcpy(*line, *keep, ft_check(*keep, '\n') + 1);
		(*line)[ft_check(*keep, '\n') + 1] = 0;
	}
	else
	{
		*line = (char *)malloc(sizeof(char) * ft_strlen(*keep) + 1);
		if (!(*line))
			return ;
		ft_memcpy(*line, *keep, ft_strlen(*keep));
		(*line)[ft_strlen(*keep)] = 0;
	}
}

void	remove_from_keep(char **keep)
{
	char	*tmp;
	size_t	line_index;

	if (!ft_check(*keep, '\n'))
	{
		*keep = NULL;
		return ;
	}
	line_index = ft_check(*keep, '\n') + 1;
	tmp = (char *)malloc(sizeof(char) * ft_strlen(*keep) - line_index);
	if (!tmp)
		return ;
	ft_memcpy(tmp, *keep + line_index, ft_strlen(*keep) - line_index);
	free(*keep);
	(*keep) = NULL;
	*keep = (char *)malloc(sizeof(char) * ft_strlen(tmp) + 1);
	(*keep)[ft_strlen(tmp)] = 0;
	ft_memcpy(*keep, tmp, ft_strlen(tmp));
	free(tmp);
}

void	store_in_keep(int fd, int *bytes_read, char **keep)
{
	char	*tmp;

	tmp = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	tmp[BUFFER_SIZE] = 0;
	while (!(ft_check(*keep, '\n')) && (*bytes_read) != 0)
	{
		tmp = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
		tmp[BUFFER_SIZE] = 0;
		*bytes_read = (int)read(fd, tmp, BUFFER_SIZE);
		if ((*bytes_read) > 0)
		{
			*keep = ft_strjoin(*keep, tmp);
			if (!(*keep))
			{
				free(tmp);
				return ;
			}
		}
		free(tmp);
	}
	// free(tmp);
}

char	*get_next_line(int fd)
{
	static char	*keep;
	int			bytes_read;
	char		*line;

	bytes_read = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!keep || !ft_check(keep, '\n'))
	{
		store_in_keep(fd, &bytes_read, &keep);
		if (bytes_read == 0 && !keep)
		{
			free(keep);
			return (NULL);
		}
	}
	// printf("keep = %s", keep);
	store_in_line(&keep, &line);
	if (!line)
		return (NULL);
	// if (bytes_read > 0)
	remove_from_keep(&keep);
	return (line);
}

// int	main(void)
// {
// 	int fd = open("text.txt", O_RDONLY);
// 	printf("%d\n", fd);
	
	// char	*s;
	
	// s = "";
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));

	// while (s)
	// {
	// 	s = get_next_line(fd);
	// 	printf("%s", s);
	// 	free(s);
	// }
	// s = get_next_line(fd);
	// printf("%s\n", s);
	// free(s);
// }