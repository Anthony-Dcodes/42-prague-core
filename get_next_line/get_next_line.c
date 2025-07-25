/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 17:40:27 by advorace          #+#    #+#             */
/*   Updated: 2025/07/25 14:41:09 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*stash;
	size_t		bytes_read;
	char		*line;

	bytes_read = (read(fd, buf, BUFFER_SIZE));
	while (bytes_read > 0)
	{
		buf[bytes_read] = '\0';
		if (!stash)
		{
			stash = malloc(1);
			if (stash)
				stash[0] = '\0';
		}
		//printf("stash before join_and_free:%s\n", stash);
		stash = join_and_free(stash, buf);
		//printf("Stash so far:%s\n", stash);
		if (ft_strchr(stash, '\n'))
		{
			line = new_line(stash);
			stash = new_stash(stash);
			//printf("line:%s\n", line);
			//printf("stash:%s\n", stash);
			return (line);
		}
		bytes_read = (read(fd, buf, BUFFER_SIZE));
	}
	while (stash)
	{
		if (ft_strchr(stash, '\n'))
		{
			line = new_line(stash);
			stash = new_stash(stash);
			//printf("line:%s\n", line);
			//printf("stash:%s\n", stash);
			return (line);
		}
		else
			return (stash);
	}
	return (NULL);
}
