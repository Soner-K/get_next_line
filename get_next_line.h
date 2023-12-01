/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 17:03:26 by sokaraku          #+#    #+#             */
/*   Updated: 2023/12/01 19:44:26 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

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

size_t				ft_strlen(char const *s);
int					ft_check(char const *s, char c);
void				*ft_memcpy(void *dest, const void *src, size_t n);
char				*ft_strjoin(char const *s1, char const *s2, int bytes_read);
void				store_in_line(char **keep, char **line);
void				remove_from_keep(char **keep);
void				store_in_keep(int fd, int *bytes_read, char **keep);
char				*get_next_line(int fd);

#endif