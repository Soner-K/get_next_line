/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:08:20 by sokaraku          #+#    #+#             */
/*   Updated: 2023/11/24 23:28:13 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/*Initialize a new node in which the content is the nbytes from the read function */
t_list	*ft_lstnew(size_t nbytes, int fd)
{
	t_list	*new;
	char	*str;

	new = malloc(sizeof(t_list));
	str = malloc(sizeof(char) * nbytes + 1);
	if (!str || !new)
		return (NULL);
	read(fd, str, nbytes);
	str[nbytes] = 0;
	// printf("str dans ft_lstnew = %s\n", str);
	new->content = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!(new->content))
		return (NULL);
	ft_memcpy(new->content, str, ft_strlen(str));
	new->content[ft_strlen(str)] = 0;
	free(str);
	// new->next = 0;
	return (new);
}

char	*ft_findline(char *str, int fd, t_list **lst)
{
	char	*new;
	t_list	*first;

	if (*str)
		ft_memcpy((*lst)->content, str, ft_strlen(str));
	else
		*lst = ft_lstnew(BUFFER_SIZE, fd);
	first = *lst;
	if (!(*lst))
		return (NULL); // retourner null?
	while (!ft_check((*lst)->content, '\n'))
	{
		(*lst) = (*lst)->next; // laisser ici si ftmemcp car la liste navance pas avant
		(*lst) = ft_lstnew(BUFFER_SIZE, fd);
		if (!(*lst))
			return (NULL);
	}
	(*lst)->next = NULL;
	*lst = first;
	new = malloc(sizeof(char) * ft_lstlen(*lst, 1) + 1);
	if (!str)
		return (NULL);
	new[ft_lstlen(*lst, 1)] = 0;
	ft_lst_to_str(new, *lst);
	// *lst = first;
	ft_lstclear(lst, free);
	return (new);
}

char	*ft_newkeep(char *str)
{
	size_t		index_cut;
	static char	*new_keep;

	if (!ft_check(str, '\n'))
		return (str);
	index_cut = ft_check(str, '\n') + 1;
	new_keep = malloc(sizeof(char) * ft_strlen(str) + 1 - index_cut);
	if (!new_keep)
		return (NULL);
	ft_memcpy(new_keep, str + index_cut, ft_strlen(str) - index_cut);
	new_keep[ft_strlen(str) - index_cut] = 0;
	free(str);
	return (new_keep);
}

char	*ft_cut(char *str)
{
	size_t	index_cut;
	char	*line;

	index_cut = ft_check(str, '\n') + 1;
	line = malloc(sizeof(char) * index_cut + 1);
	if (!line)
		return (NULL);
	ft_memcpy(line, str, index_cut);
	line[index_cut] = 0;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*keep;
	static char	*first;
	char		*line;
	t_list		*lst;

	printf("keep debut gnl %s\n", keep);
	if (!keep || !ft_check(keep, '\n'))
	{
		keep = ft_findline(keep, fd, &lst);
		// prototypée en char keep restera static ?
		first = keep;
		printf("keep si !keep %s\n", keep);
	}
	line = malloc(sizeof(char) * ft_check(keep, '\n'));
	if (!line)
		return (NULL);
	line = ft_cut(keep);
	keep = ft_newkeep(keep);
	printf("keep apres newkeep %s\n", keep);
	if (!line)
		return (NULL);
	if (!keep)
	{
		keep = first;
		free(keep);
	}
	printf("keep fin gnl = %s\n", keep);
	return (line);
}

int	main(void)
{
	int fd = open("text.txt", O_RDONLY);
	printf("gnl = %s", get_next_line(fd));
	printf("gnl = %s", get_next_line(fd));
	printf("gnl = %s", get_next_line(fd));
}