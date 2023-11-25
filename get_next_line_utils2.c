/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:08:17 by sokaraku          #+#    #+#             */
/*   Updated: 2023/11/25 21:39:11 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

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


void	ft_lstclear(t_list **lst, void (*del)(void *))
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

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
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

// int	main(void)
// {
// 	t_list	*lst;
// 	t_list	*lst2;
// 	t_list	*lst3;
// 	char	*str;
// 	size_t	count;

// 	count = 0;
// 	lst = malloc(sizeof(t_list));
// 	lst2 = malloc(sizeof(t_list));
// 	lst3= malloc(sizeof(t_list));
// 	if (!lst || !lst2 || !lst3)
// 		return (0);
// 	lst->content = malloc(sizeof(char) * 11);
// 	lst2->content = malloc(sizeof(char) * 11);
// 	lst3->content = malloc(sizeof(char) * 11);
// 	if (!lst->content || !lst2->content || !lst3->content)
// 		return (0);
// 	lst->content[10] = 0;
// 	lst2->content[10] = 0;
// 	lst3->content[10] = 0;
// 	strcpy(lst->content, "salutsalut");
// 	strcpy(lst2->content, "salutsalut");
// 	strcpy(lst3->content, "salutsalut");
// 	lst->next = lst2;
// 	lst2->next = lst3;
// 	lst3->next = NULL;
// 	str = malloc(sizeof(char) * ft_lstlen(lst, 0) + 1);
// 	if (!str)
// 		return (0);
// 	ft_lst_to_str(&str, lst);
// 	printf("%s\n", str);
// 	free(lst->content);
// 	free(lst2->content);
// 	free(lst3->content);
// 	free(lst);
// 	free(lst2);
// 	free(lst3);
// 	free(str);
// }