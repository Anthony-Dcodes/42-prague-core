/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 15:43:14 by advorace          #+#    #+#             */
/*   Updated: 2025/06/01 11:12:58 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

// Count the number of words is s
static int	ft_count_words(const char *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

// Free all allocated memmory to arr
static void	free_all(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

// Add word to result
static int	add_word(char **result, int i, const char *start, int len)
{
	char	*word;

	word = ft_strdup(start);
	if (!word)
	{
		free_all(result);
		return (-1);
	}
	word[len] = '\0';
	result[i] = word;
	return (0);
}

// Iteratively call add_word untill you reach end of string
static char	**ft_split_fill(char const *s, char c, char **result)
{
	int		i;
	int		start;
	int		end;

	i = 0;
	start = 0;
	end = 0;
	while (s[end])
	{
		while (s[end] && s[end] == c)
			end++;
		start = end;
		while (s[end] && s[end] != c)
			end++;
		if (end > start)
		{
			if (add_word(result, i, s + start, end - start) == -1)
				return (NULL);
			i++;
		}
	}
	result[i] = NULL;
	return (result);
}

// Split s on c and add words to **result untill complete
// Mark end of array with NULL
// Return the resulting array
char	**ft_split(char const *s, char c)
{
	char	**result;

	if (!s)
		return (NULL);
	result = malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!result)
	{
		return (NULL);
	}
	if (!ft_split_fill(s, c, result))
	{
		free_all(result);
		return (NULL);
	}
	return (result);
}
