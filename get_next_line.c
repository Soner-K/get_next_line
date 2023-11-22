/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:50:04 by sokaraku          #+#    #+#             */
/*   Updated: 2023/11/22 16:06:34 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "get_next_line.h"
#include <fcntl.h>

/*Initialize a new node in which the content is the nbytes from the read function */
t_list	*ft_lstnew(size_t nbytes, int fd, int *number_node)
{
	t_list	*new;
	char	*str;

	new = malloc(sizeof(t_list));
	str = malloc(sizeof(char) * nbytes + 1);
	if (!str || !new)
		return (NULL);
	read(fd, str, nbytes);
	str[nbytes] = 0;
	new->content = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!(new->content))
		return (NULL);
	ft_memcpy(new->content, str, ft_strlen(str));
	new->content[ft_strlen(str)] = 0;
	free(str);
	new->next = 0;
	(*number_node)++;
	return (new);
}

/*delete a node and set the list to begin at the next node*/
void	ft_lstdel_and_move(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;

	ptr = (*lst)->next;
	if (!(*lst) || !del)
		return ;
	del((*lst)->content);
	free(lst);
	*lst = ptr;
}

/*work in progress (might not need it)*/
// void	ft_lstclear(t_list **lst, void (*del)(void *), size_t to_del)
// {
// 	t_list	*ptr;

// 	if (!lst || !del)
// 		return ;
// 	while ((to_del--))
// 	{
// 		ptr = (*lst)->next;
// 		ft_lstdelone(*lst, del);
// 		*lst = ptr;
// 	}
// }

/*calculate the number of bytes (i.e. characters) until a line return*/
size_t	ft_lst_to_line(t_list *lst)
{
	int		i;
	size_t	count;

	i = 0;
	count = 0;
	while (lst)
	{
		while (lst->content[i])
		{
			if (lst->content[i] == '\n')
			{
				count += i;
				return (count);
			}
			i++;
		}
		count += i;
		i = 0;
		lst = lst->next;
	}
	return (count);
}
/*lst_to_line test
*/

// int	main(void)
// {
// 	t_list	*lst;
// 	t_list	*lst2;
// 	t_list	*lst3;
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
// 	strcpy(lst3->content, "\nsalutsalut");
// 	lst->next = lst2;
// 	lst2->next = lst3;
// 	lst3->next = NULL;
// 	count = ft_lst_to_line(lst);
// 	printf("%zu\n", count);
// }