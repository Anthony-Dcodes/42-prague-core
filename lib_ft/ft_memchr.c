/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:03:32 by advorace          #+#    #+#             */
/*   Updated: 2025/05/30 14:22:07 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*prt;

	i = 0;
	prt = (const unsigned char *)s;
	while (i < n)
	{
		if (prt[i] == (unsigned char)c)
			return ((void *)(prt + i));
		i++;
	}
	return (NULL);
}
