/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:14:01 by sokaraku          #+#    #+#             */
/*   Updated: 2023/12/07 17:01:51 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(char const *s);
int		ft_check(char const *s, char c);
char	*ft_fuse(char *s1, char *s2);
char	*keep_to_line(char *keep);
char	*file_to_keep(int fd, char *keep, int *bytes_read);
char	*get_next_line(int fd);
char	*remove_from_keep(char *line, char *keep);
#endif