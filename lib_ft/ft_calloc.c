/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 17:26:32 by advorace          #+#    #+#             */
/*   Updated: 2025/05/31 13:11:24 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

// Allocate mem to array of nmemb elements of size bytes
// Return pointer to allocated mem or NULL if fail
void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			total_mem;
	size_t			i;
	unsigned char	*prt;

	i = 0;
	total_mem = nmemb * size;
	if (total_mem == 0)
		return (malloc(1));
	prt = malloc(total_mem);
	if (prt == NULL)
		return (NULL);
	while (i < total_mem)
	{
		prt[i] = 0;
		i++;
	}
	return (prt);
}
