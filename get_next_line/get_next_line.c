/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 17:40:27 by advorace          #+#    #+#             */
/*   Updated: 2025/08/20 20:22:55 by advorace         ###   ########.fr       */
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
		return (NULL);
	++p_rest;
	if (*p_rest == '\0')
		return (NULL);
	len = ft_strlen(p_rest);
	new_stash = malloc(len + 1);
	if (!new_stash)
		return (NULL);
	ft_memcpy(new_stash, p_rest, len);
	new_stash[len] = '\0';
	return (new_stash);
}

static int	cleanup_init(char **buf, char **st, ssize_t b_read, int init_st)
{
	if (b_read == -1)
	{
		free(*buf);
		*buf = NULL;
		if (*st)
		{
			free(*st);
			*st = NULL;
		}
		return (0);
	}
	if (!*st && init_st)
	{
		*st = malloc(1);
		if (!*st)
		{
			free(*buf);
			*buf = NULL;
			return (0);
		}
		(*st)[0] = '\0';
	}
	return (1);
}

static char	*return_line_update_stash(char **stash, char **buf)
{
	char	*n_line;
	char	*tmp;

	if (!stash || !*stash || !buf)
	{
		free(*buf);
		*buf = NULL;
		free(*stash);
		*stash = NULL;
		return (NULL);
	}
	n_line = new_line(*stash);
	tmp = new_stash(*stash);
	free(*stash);
	*stash = tmp;
	free(*buf);
	*buf = NULL;
	if (!n_line || !stash)
	{
		free(*stash);
		*stash = NULL;
	}
	return (n_line);
}

static char	*read_and_process(int fd, char **stash, char **buf)
{
	ssize_t	bytes_read;

	bytes_read = read(fd, *buf, BUFFER_SIZE);
	if (!cleanup_init(buf, stash, bytes_read, 0))
		return (NULL);
	while (bytes_read > 0)
	{
		(*buf)[bytes_read] = '\0';
		if (!cleanup_init(buf, stash, bytes_read, 1))
			return (NULL);
		*stash = join_and_free(stash, buf);
		if (!*stash)
			return (NULL);
		if (ft_strchr(*stash, '\n'))
			return (return_line_update_stash(stash, buf));
		bytes_read = (read(fd, *buf, BUFFER_SIZE));
		if (!cleanup_init(buf, stash, bytes_read, 0))
			return (NULL);
	}
	if (*stash)
		return (return_line_update_stash(stash, buf));
	free(*buf);
	*buf = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*stash;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
	{
		if (!cleanup_init(&buf, &stash, -1, 0))
			return (NULL);
	}
	return (read_and_process(fd, &stash, &buf));
}
