/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 17:04:17 by sokaraku          #+#    #+#             */
/*   Updated: 2023/11/26 22:24:47 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line2.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*Initialize a new node in which the content is the BUFFER_SIZE from the read function */
t_list	*ft_lstnew(int fd, int *return_read)
{
	t_list	*new;
	char	*str;

	new = malloc(sizeof(t_list));
	str = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!str || !new)
		return (NULL);
	*return_read = read(fd, str, BUFFER_SIZE);
	str[*return_read] = '\0';
	// printf("str dans ft_lstnew = %s\n", str);
	new->content = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!(new->content))
		return (NULL);
	ft_memcpy(new->content, str, ft_strlen(str));
	new->content[ft_strlen(str)] = '\0';
	free(str);
	return (new);
}
int	read_and_store(t_list **lst, int fd)
{
	t_list	*first;
	int		return_read;

	return_read = 0;
	(*lst) = ft_lstnew(fd, &return_read);
	if (!(*lst))
		return (0);
	first = *lst;
	while (1)
	{
		if (!(*lst) || !(*lst)->content || return_read < 0) // si erreur dans read que faire ?
// si alloc echoue, liberer toute la liste ou stocker jusqu'au noeud NULL dans str?
			return 0;
		if (ft_check((*lst)->content, '\n') || return_read == '\0')
			break ;
		(*lst)->next = ft_lstnew(fd, &return_read);
		(*lst) = (*lst)->next;
	}
	(*lst) = first;
	return (return_read);
}

void	lst_to_keep(t_list *lst, char **keep)
{
	size_t	len_keep;
	size_t	copied;
	char	*tmp;
	
	len_keep = ft_strlen(*keep);
	copied = 0;
	tmp = malloc(sizeof(char) * (ft_lstlen(lst) + len_keep + 1));
	if (!tmp)
		return ;
	tmp[ft_lstlen(lst) + len_keep] = 0;
	tmp = (char *) ft_memcpy(tmp, *keep, len_keep);
	copied = len_keep;
	while (lst)
	{
		ft_memcpy(tmp + copied, lst->content, ft_strlen(lst->content));
		copied += ft_strlen(lst->content);
		lst = lst->next;
	}
	free(*keep);
	(*keep) = NULL;
	*keep = malloc(sizeof(char) * copied + 1);
	(*keep)[copied] = 0;
	ft_memcpy(*keep, tmp, copied);
	free(tmp);
}

char	*keep_to_line(char *str, char **keep)
{
	size_t	i;
	size_t	j;
	char	*tmp;

	i = 0;
	j = 0;
	while (1)
	{
		str[i] = (*keep)[j++];
		if (str[i++] == '\n' || i >= ft_strlen(*keep))
			break ;
	}
	tmp = malloc(sizeof(char) * ft_strlen(*keep) - j + 1);
	if (!tmp)
		return (NULL);
	tmp[ft_strlen(*keep) - j] = 0;
	ft_memcpy(tmp, (*keep) + j, ft_strlen(*keep) - j);
	free(*keep);
	// (*keep) = NULL;
	(*keep) = malloc(sizeof(char) * ft_strlen(tmp) + 1);
	if (!(*keep))
		return (NULL);
	(*keep)[ft_strlen(tmp)] = 0;
	ft_memcpy(*keep, tmp, ft_strlen(tmp));
	free(tmp);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*keep;
	char		*line;
	int			return_read;
	t_list		*lst;

	return_read = 0;
	if (!keep || !(ft_check(keep, '\n')))
	{
		return_read = read_and_store(&lst, fd);
		if (!lst || !lst->content || (ft_lstlen(lst) == 0))
			return (NULL);
		lst_to_keep(lst, &keep);
		if (!keep)
			return (NULL);
	}
	line = malloc(sizeof(char) * ft_check(keep, '\n') + 1);
	if (!line)
		return (NULL);
	line[ft_check(keep,'\n')] = 0;
	line = keep_to_line(line, &keep);
	if (!line || !keep)
		return (NULL);
	ft_lstclear(&lst, free);
	return (line);
}

int main()
{
	int fd = open("text.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}
/* 
int main()
{
	t_list *lst;
	t_list *lst2;
	t_list *lst3;
	char	*str;

	str = malloc(sizeof(char) * 2);
	str[0] = 0;
	str[1] = 0;
	lst = malloc(sizeof(t_list));
	lst->content = malloc(sizeof(char) * 10);
	lst2 = malloc(sizeof(t_list));
	lst2->content = malloc(sizeof(char) * 10);
	lst3 = malloc(sizeof(t_list));
	lst3->content = malloc(sizeof(char) * 10);
	strcpy(lst->content, "lst1");
	strcpy(lst2->content, "lst2");
	strcpy(lst3->content, "lst3");
	lst->content[4] = 0;
	lst2->content[4] = 0;
	lst3->content[4] = 0;
	lst->next = lst2;
	lst2->next = lst3;
	lst3->next = NULL;
	lst_to_keep(lst, &str);
	printf("str = %s\n", str);
	free(lst->content);
	free(lst2->content);
	free(lst3->content);
	free(lst);
	free(lst2);
	free(lst3);
	free(str);
	
} */