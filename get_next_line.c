/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:50:04 by sokaraku          #+#    #+#             */
/*   Updated: 2023/11/21 16:06:31 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_check(char *str, int c)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (unsigned char)c)
			return (1);
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

char	*ft_strdup(const char *s)
{
	char	*ptr;

	ptr = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, s, ft_strlen(s) + 1);
	return (ptr);
}

char	*ft_line(char *str, size_t nbytes, int fd)
{
	size_t		size;
	static char	*stat_str;

	size = 0;
	//malloc str dans get next line
	while (ft_check((char *) stat_str, '\n'))
	{
		size += read(fd, stat_str, nbytes);
		if (!str)
			{
				stat_strmalloc(sizeof);
				stat_str = ft_strdup();
			}
	}
}

char	*get_next_line(void)
{
	static char	*keep;
	char		*str;
}

int	main(void)
{
	printf("%s\n", get_next_line());
}