/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:57:12 by sokaraku          #+#    #+#             */
/*   Updated: 2023/11/25 21:48:21 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

size_t	ft_lstlen(t_list *lst, char binary)
{
	size_t	count;

	count = 0;
	if (binary == 1)
	{
		while (lst)
		{
			count += ft_strlen(lst->content);
			lst = lst->next;
		}
		return (count);
	}
	while (lst)
	{
		if (ft_check(lst->content, '\n') || (*(lst->content) == '\n'))
		{
			count += ft_check(lst->content, '\n');
			return (count);
		}
		else
			count += ft_strlen(lst->content);
		lst = lst->next;
	}
	return (count);
}

void	ft_lst_to_str(char **str, t_list *first)
{
	long	i;
	char		one;
	size_t	j;

	one = (ft_lstlen(first, 0) == ft_lstlen(first, 1));
	*str = malloc(sizeof(char) * ft_lstlen(first, 0) + 1 + one) ; //SD
	if (!(*str) || !first)
		return ;
	i = 0;
	j = 0;
	while (first)
	{
		while (first->content[j])
		{
			(*str)[i] = first->content[j++];
			if ((*str)[i] == '\n')
				{
					(*str)[i + 1] = 0;
					return ;
				}
			i++;
		}
		first = first->next;
		j = 0;
	}
}

/*Initialize a new node in which the content is the nbytes from the read function */
t_list	*ft_lstnew(size_t nbytes, int fd, int *return_read)
{
	t_list	*new;
	char	str[BUFFER_SIZE + 1];

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	(*return_read) = read(fd, str, nbytes);
	str[nbytes] = 0;
	new->content = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!(new->content))
		return (NULL);
	ft_memcpy(new->content, str, ft_strlen(str));
	new->content[ft_strlen(str)] = 0;;
	new->next = 0;
	return (new);
}

char	*get_next_line(int fd)
{
	static t_list	*lst;
	t_list			*first_node;
	char			*line;
	int				r; // return read
	// int				number_node;

	r = 0;
	lst = malloc(sizeof(t_list));
	lst->content = malloc(sizeof(char) * BUFFER_SIZE);
	if (!lst || !lst->content)
		return (NULL);
	first_node = lst;
	while (1)
	{
		lst->next = ft_lstnew(BUFFER_SIZE, fd, &r);
		lst = lst->next;
		if (!lst || !lst->content)
			return (NULL); // peut etre free dans ce cas-la ?
		if (ft_check(lst->content, '\n')|| lst->content[0] == '\n' || r <= 0)
			break ;
	}
	ft_lst_to_str(&line, first_node);
	if (!line)
		return (NULL);
	return (line);
}

int main()
{
	int fd = open("text.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}