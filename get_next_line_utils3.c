/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:57:05 by sokaraku          #+#    #+#             */
/*   Updated: 2023/11/25 21:45:56 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_check(char *str, int c)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (0);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_2;
	unsigned char	*src_2;

	if (!dest && !src && n != 0)
		return (NULL);
	dest_2 = dest;
	src_2 = (unsigned char *)src;
	while (n)
	{
		*dest_2 = *src_2;
		dest_2++;
		src_2++;
		n--;
	}
	return (dest);
}

// void	ft_lstupdate(t_list **lst)
// {
// 	static char	*line;

// 	line = malloc(sizeof(char) * ft_check(*lst, '\n', 0));
// 	if (!line)
// 		return (NULL);
// }

// int	ft_lststat(int fd)
// {
// 	t_list			*new;
// 	t_list			*first_node;
// 	static t_list	*lst;

// 	lst = NULL; // necessaire ?
// 	first_node = lst;
// 	new = malloc(sizeof(t_list));
// 	new->content = malloc(sizeof(char) * BUFFER_SIZE + 1); // allocation trop grande si fichier termine avant BUFFER octets
// 	if (!new || !new->content)
// 		return (0);
// 	if (ft_check(lst, '\n', 0))
// 	{
// 		ft_lst_to_str()
// 		ft_lstupdate(&first_node);
// 	}
// 	read(fd, new->content, BUFFER_SIZE);
// 	new->content[BUFFER_SIZE] = 0;
// 	ft_lstlast(lst)->next = new;
// 	new->next = 0;
// 	return (1);
// 	// if (ft_check(new, '\n'))
// 	// 	return (1);
// 	// return (2);
// }

// int	main(void)
// {
// 	t_list *lst;
// 	t_list *lst2;
// 	t_list *lst3;

// 	lst = malloc(sizeof(t_list));
// 	lst->content = malloc(sizeof(char) * 10);
// 	lst2 = malloc(sizeof(t_list));
// 	lst2->content = malloc(sizeof(char) * 10);
// 	lst3 = malloc(sizeof(t_list));
// 	lst3->content = malloc(sizeof(char) * 10);
// 	strcpy(lst->content, "lst0");
// 	strcpy(lst2->content, "lst2");
// 	strcpy(lst3->content, "lst3");
// 	lst->content[4] = 0;
// 	lst2->content[4] = 0;
// 	lst3->content[4] = 0;
// 	lst->next = lst2;
// 	lst2->next = lst3;
// 	lst3->next = NULL;
// 	printf("%s\n", lst->content);
// 	t_list *last = ft_lstlast(lst);
// 	printf("%s\n", last->content);
// 	printf("%s\n", lst->content);
// }