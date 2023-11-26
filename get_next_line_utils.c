/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 17:04:19 by sokaraku          #+#    #+#             */
/*   Updated: 2023/11/26 22:28:56 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

size_t	ft_strlen(char const *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_check(char const *s, char c)
{
	size_t	i;

	i = 0;
	if (s[0] == '\n')
		return (1);
	while (s[i])
	{
		if (s[i] == c)
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

void	ft_lstclear(t_list **lst, void (*del)(void *)) // check si ok
{
	t_list	*ptr;

	if (!lst || !del)
		return ;
	while ((*lst))
	{
		ptr = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = ptr;
	}
}

size_t	ft_lstlen(t_list *lst)
{
	size_t	i;

	i = 0;
	while (lst)
	{
		i += ft_strlen(lst->content);
		lst = lst->next;	
	}
	return (i);
}