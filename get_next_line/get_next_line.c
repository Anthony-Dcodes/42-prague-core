/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 17:40:27 by advorace          #+#    #+#             */
/*   Updated: 2025/07/18 20:46:15 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*temp;
	char	*str;
	char	*buff;
	int		i;

	buff = malloc(1);
	str = malloc(2);
	str[1] = '\0';
	i = 0;
	while (read(fd, buff, 1) == 1)
	{
		str[i] = buff[0];
		temp = str;
		free(str);
		str = malloc(i + 3);


	}
}
