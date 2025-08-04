/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 17:40:27 by advorace          #+#    #+#             */
/*   Updated: 2025/08/04 20:58:01 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*new_line(char *stash)
{
	char	*ptr_to_n;
	char	*new_line;
	size_t	len;

	ptr_to_n = ft_strchr(stash, '\n');
	if (ptr_to_n)
		len = ptr_to_n - stash + 1;
	else
		len = ft_strlen(stash);
	new_line = malloc(len + 1);
	if (!new_line)
		return (NULL);
	ft_memcpy(new_line, stash, len);
	new_line[len] = '\0';
	return (new_line);
}

static char	*new_stash(char *stash)
{
	char	*p_rest;
	char	*new_stash;
	size_t	len;

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

static void	initialize_stash(char **stash)
{
	if (!*stash)
	{
		*stash = malloc(1);
		if (*stash)
			*stash[0] = '\0';
	}
}

static char	*return_line_update_stash(char **stash)
{
	char	*line;

	line = new_line(*stash);
	*stash = new_stash(*stash);
	return (line);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*stash;
	long		bytes_read;

	bytes_read = (read(fd, buf, BUFFER_SIZE));
	while (bytes_read > 0)
	{
		buf[bytes_read] = '\0';
		initialize_stash(&stash);
		stash = join_and_free(stash, buf);
		if (ft_strchr(stash, '\n'))
			return (return_line_update_stash(&stash));
		bytes_read = (read(fd, buf, BUFFER_SIZE));
	}
	while (stash)
		return (return_line_update_stash(&stash));
	return (NULL);
}
