/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 17:44:16 by advorace          #+#    #+#             */
/*   Updated: 2025/09/11 17:30:15 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#define INT_MAX 2147483647
#define INT_MIN (-2147483647 -1)

#include "libft.h"
#include "ft_printf.h"
#include "stdio.h"

int	ft_atoi_safe(const char *nptr, int *out);
typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
} t_stack;

t_stack	*stack_new(int num);
void	stack_add_back(t_stack **lst, t_stack *new);
t_stack	*stack_last(t_stack *lst);
void	stack_free(t_stack *lst);

#endif
