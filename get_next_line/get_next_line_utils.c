/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 17:44:43 by advorace          #+#    #+#             */
/*   Updated: 2025/07/28 20:55:53 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stddef.h>

// Returns pointer to the first occurance of c in s
char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if ((char)c == '\0')
		return ((char *)(s + i));
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*str;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = malloc(s1_len + s2_len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (*s1)
		str[i++] = *s1++;
	while (*s2)
		str[i++] = *s2++;
	str[i] = '\0';
	return (str);
}
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
char	*join_and_free(char *stash, char *buf)
{
	char	*new;

	new = ft_strjoin(stash, buf);
	free(stash);
	return (new);
}
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	if (!dst && !src)
		return (dst);
	i = 0;
	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}
char	*new_line(char *stash)
{
	char	*ptr_to_n;
	char	*new_line;
	size_t	len;

	ptr_to_n = ft_strchr(stash, '\n');
	len = ptr_to_n - stash + 1;
	new_line = malloc(len + 1);
	if (!new_line)
		return (NULL);
	ft_memcpy(new_line, stash, len);
	new_line[len] = '\0';
	return (new_line);
}
char *new_stash(char *stash)
{
	char *p_rest;
	char *new_stash;
	size_t len;

	p_rest = ft_strchr(stash, '\n');
	if (!p_rest)
	{
		free(stash);
		return (NULL);
	}
	++p_rest;
	if (*p_rest == '\0')
	{
		free(stash);
		return (NULL);
	}
	len = ft_strlen(p_rest);
	new_stash = malloc(len + 1);
	if (!new_stash)
		return (NULL);
	ft_memcpy(new_stash, p_rest, len);
	new_stash[len] = '\0';
	free(stash);
	return (new_stash);
}

