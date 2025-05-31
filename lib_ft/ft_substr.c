/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 11:21:12 by advorace          #+#    #+#             */
/*   Updated: 2025/05/31 12:07:14 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	i;
	
	if (!s)
		return (NULL);
	if ((size_t)start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s))
		len = ft_strlen(s + start);
	sub_str = ft_calloc(len + 1, sizeof(char));
	if (!sub_str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub_str[i] = s[start + i];
		i++;
	}
	return (sub_str);
}

#ifdef TEST
#include <stdio.h>

int	main(void)
{
	char	*str = "Hello world!";
	char	*sub = ft_substr(str, 6, 3);

	if (sub)
	{
		printf("Result: %s\n", sub); // Expected: "wor"
		free(sub);
	}
	else
	{
		printf("Returned NULL\n");
	}
	return 0;
}
#endif