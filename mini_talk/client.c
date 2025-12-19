/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 19:55:07 by advorace          #+#    #+#             */
/*   Updated: 2025/12/19 15:27:50 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	main(int argc, char *argv[])
{
	pid_t	pid;
	char	*str;
	int		i;
	int		bit;
	char	c;
	
	if (argc != 3)
		return (1);
	pid = ft_atoi(argv[1]);
	str = argv[2];
	i = 0;
	while (str[i])
	{
		bit = 7;
		c = str[i];
		while (bit >= 0)
		{
			if ((c >> bit) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(500);
			--bit;
		}
		++i;
	}
	return (0);
}
