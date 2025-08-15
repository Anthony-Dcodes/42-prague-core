/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 17:40:27 by advorace          #+#    #+#             */
/*   Updated: 2025/08/15 17:14:07 by advorace         ###   ########.fr       */
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
	{
		free(stash);
		return (NULL);
	}
	ft_memcpy(new_stash, p_rest, len);
	new_stash[len] = '\0';
	free(stash);
	return (new_stash);
}

// static void	initialize_stash(char **stash)
// {
// 	if (!*stash)
// 	{
// 		*stash = malloc(1);
// 		if (!*stash)
// 			return (NULL);
// 		if (*stash)
// 			(*stash)[0] = '\0';
// 	}
// }

static char	*return_line_update_stash(char **stash, char **buf)
{
	char	*line;

	if (!stash || !*stash || !buf)
	{
		free(*buf);
		*buf = NULL;
		free(*stash);
		*stash = NULL;
        return (NULL);
	}
	line = new_line(*stash);
	*stash = new_stash(*stash);
	free(*buf);
	*buf = NULL;
	if (!line)
	{
		free(*stash);
		*stash = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*stash;
	ssize_t		bytes_read;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	buf[0] = '\0';
	bytes_read = (read(fd, buf, BUFFER_SIZE));
	if (bytes_read == -1)
	{
		free(buf);
		buf = NULL;
		if (stash)
		{
			free(stash);
			stash = NULL;
		}
		return (NULL);
	}
	while (bytes_read > 0)
	{
		buf[bytes_read] = '\0';
		if (!stash)
		{
			stash = malloc(1);
			if (!stash)
			{
				free(buf);
				buf = NULL;
				return (NULL);
			}
			stash[0] = '\0';
		}
		stash = join_and_free(&stash, &buf);
		if (!stash)
			return (NULL);
		if (ft_strchr(stash, '\n'))
			return (return_line_update_stash(&stash, &buf));
		bytes_read = (read(fd, buf, BUFFER_SIZE));
		if (bytes_read == -1)
		{
			free(buf);
			buf = NULL;
			if (stash)
			{
				free(stash);
				stash = NULL;
			}
			return (NULL);
		}
	}
	if (stash)
		return (return_line_update_stash(&stash, &buf));
	free(buf);
	buf = NULL;
	return (NULL);
}
