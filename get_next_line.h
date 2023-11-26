/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 17:03:26 by sokaraku          #+#    #+#             */
/*   Updated: 2023/11/26 17:31:18 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 20
#endif

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>

size_t				ft_strlen(char const *s);
int					ft_check(char const *s, char c);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				ft_lstclear(t_list **lst, void (*del)(void *));
size_t				ft_lstlen(t_list *lst);

#endif