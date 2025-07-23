/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 17:40:27 by advorace          #+#    #+#             */
/*   Updated: 2025/07/23 19:45:47 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*stash;
	size_t		bytes_read;
	char		*line;

	stash = NULL;
	bytes_read = (read(fd, buf, BUFFER_SIZE));
	while (bytes_read > 0)
	{
		buf[bytes_read] = '\0';
		if (!stash)
			stash = malloc(1);
		stash = join_and_free(stash, buf);
		if (ft_strchr(stash, '\n'))
		{
			line = new_line(stash);
			stash = new_stash(stash);
			return (line);
		}
		bytes_read = (read(fd, buf, BUFFER_SIZE));
	}
	return (NULL);
}
