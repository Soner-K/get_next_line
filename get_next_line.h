/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:21:54 by sokaraku          #+#    #+#             */
/*   Updated: 2023/11/24 23:19:33 by sokaraku         ###   ########.fr       */
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

size_t				ft_strlen(char *s);
size_t				ft_check(char *str, char c);
void				*ft_memcpy(void *dest, const void *src, size_t n);
size_t				ft_lstlen(t_list *lst, char binary);
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lst_to_str(char *str, t_list *first);
t_list	*ft_lstnew(size_t nbytes, int fd);
char	*ft_cut(char *str);
char	*get_next_line(int fd);
char	*ft_findline(char *str, int fd, t_list **lst);
char	*ft_newkeep(char *str);


#endif