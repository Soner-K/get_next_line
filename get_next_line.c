/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:16:13 by sokaraku          #+#    #+#             */
/*   Updated: 2023/12/03 18:32:40 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

// char	*ft_fuse(char *s1, char *s2)
// {
// 	size_t	i;
// 	size_t	j;
// 	char	*new;

// 	i = -1;
// 	j = 0;
// 	if (!s1 && !s2)
// 		return (NULL);
// 	new = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
// 	if (!new)
// 		return (NULL);
// 	if (s1)
// 	{
// 		while (++s1[i])
// 		{
// 			new[i] = s1[i];
// 		}
// 	}
// 	if (s2)
// 	{
// 		while (s2[j])
// 			new[i++] = s2[j++];
// 	}
// 	new[i] = 0;
// 	return (new);
// }

char	*keep_to_line(char *keep)
{
	char	*line;
	size_t	i;

	i = 0;
	if (ft_check(keep, '\n'))
		line = ft_calloc(ft_check(keep, '\n') + 2, sizeof(char));
	else
		line = ft_calloc(ft_strlen(keep) + 1, sizeof(char));
	if (!line)
		return (NULL);
	while (keep[i] != '\n' && keep[i])
	{
		line[i] = keep[i];
		i++;
	}
	if (keep[i] == '\n')
	{
		line[i] = keep[i];
		i++;
	}
	line[i] = 0;
	return (line);
}

char	*remove_from_keep(char *line, char *keep)
{
	size_t	i;
	size_t	j;
	char	*new_keep;
	char	*to_del;

	i = ft_strlen(line);
	j = ft_strlen(keep);
	to_del = keep;
	if (!line || !keep || (j == i))
	// cas de fin de fichier ou fichier vide ?
	{
		free(keep);
		return (NULL);
	}
	// while (keep[i] && (keep[i] == line[i]))
	// 	i++;
	new_keep = ft_calloc(j - i + 1, sizeof(char));
	if (!new_keep)
		return (NULL);
	j = 0;
	while (keep[i])
		new_keep[j++] = keep[i++];
	new_keep[j] = 0;
	free(to_del);
	return (new_keep);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*keep;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, keep, 0))
		return (NULL);
	if (!ft_check(keep, '\n') || !keep)
		keep = file_to_keep(fd, keep);
	if (!keep)
		return (NULL);
	line = keep_to_line(keep);
	if (!line)
		return (NULL);
	keep = remove_from_keep(line, keep);
	if (!keep && !line)
		return (NULL);
	return (line);
}

#include <string.h>

// int	main(void)
// {
// 	int fd;
// 	char *s;

// 	fd = open("nl", O_RDONLY);
// 	s = "";
// 	while (s)
// 	{
// 		s = get_next_line(fd);
// 		printf("gnl = %s", s);
// 		free(s);
// 	}
// 	free(s);
// }