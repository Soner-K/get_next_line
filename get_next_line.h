/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:21:54 by sokaraku          #+#    #+#             */
/*   Updated: 2023/11/22 11:54:09 by sokaraku         ###   ########.fr       */
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
#endif