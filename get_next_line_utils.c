/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 14:34:49 by sokaraku          #+#    #+#             */
/*   Updated: 2023/12/03 18:36:11 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
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
	if (!s)
		return (0);
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

// char	*ft_fuse(char const *s1, char const *s2)
// {
// 	size_t	i;
// 	size_t	j;
// 	char	*new;

// 	i = 0;
// 	j = 0;
// 	if (!s1 && !s2)
// 		return (NULL);
// 	new = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
// 	if (!new)
// 		return (NULL);
// 	if (s1)
// 	{
// 		while (s1[i])
// 		{
// 			new[i] = s1[i];
// 			i++;
// 		}
// 	}
// 	if (s2)
// 	{
// 		while (s2[j])
// 			new[i++] = s2[j++];
// 	}
// 	new[i] = 0;
// 	return (new);
// }

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*new;
	size_t		len_s1;
	size_t		len_s2;

	if (!s1 && !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	new = (char *)ft_calloc(len_s1 + len_s2 + 1, sizeof(char));
	if (!new)
		return (NULL);
	ft_memcpy(new, s1, len_s1);
	ft_memcpy(new + len_s1, s2, len_s2);
	new[len_s1 + len_s2] = '\0';
	return (new);
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


void	ft_bzero(void *s, size_t n)
{
	unsigned char	*one_b;

	if (s == NULL && n == 0)
		return ;
	one_b = s;
	while (n--)
	{
		*one_b = 0;
		one_b++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if ((size != 0) && nmemb >= __SIZE_MAX__ / size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	if (nmemb == 0 || !size)
		return (ptr);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

char	*file_to_keep(int fd, char *keep)
{
	char	tmp[BUFFER_SIZE + 1];
	char	*to_del;
	int		bytes_read;

	bytes_read = 1;
	while (!ft_check(keep, '\n') && bytes_read > 0)
	{
		tmp[BUFFER_SIZE] = 0;
		bytes_read = read(fd, tmp, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(keep);
			return (NULL);
		}
		if (bytes_read > 0)
		{
			to_del = keep;
			keep = ft_strjoin(keep, tmp);
			free(to_del);
			if (!keep)
				return (NULL);
		}
		// ft_bzero(tmp, BUFFER_SIZE);
	}
	return (keep);
}

// int	main(void)
// {
// 	char *s;

// 	s = NULL;
// 	int fd = open("text.txt", O_RDONLY);
// 	s = ft_line(fd, s);
// 	printf("%s\n", s);
// 	free(s);
// }