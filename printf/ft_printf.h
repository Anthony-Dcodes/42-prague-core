/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 19:30:28 by advorace          #+#    #+#             */
/*   Updated: 2025/07/02 18:59:22 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdlib.h>
# include <stdarg.h>
# include "ft_printf.h"
# include <unistd.h>

int		ft_printf(const char *, ...);
void	ft_process_c(char c);
void	ft_process_s(char *s);
void	ft_process_d(int i);
int		handle_sc_formats(char format_specifier, va_list args);
void	put_unsigned_int(unsigned int n, int fd);

#endif
