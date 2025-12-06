/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 19:55:07 by advorace          #+#    #+#             */
/*   Updated: 2025/12/06 14:06:17 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	main(int argc, char *argv[])
{
	char	*pid;
	char	*string;
	
	pid = argv[1];
	string = argv[2];
	ft_printf("Number of arguments: %i\n", argc);
	ft_printf("Arg 0: %s\n", argv[0]);
	ft_printf("Pid: %s\n", pid);
	ft_printf("String: %s\n", string);
	return (0);
}
