/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 17:38:21 by advorace          #+#    #+#             */
/*   Updated: 2025/07/23 19:04:26 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*join_and_free(char *stash, char *buf);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char 	*new_line(char *stash);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*new_stash(char *stash);

#endif
