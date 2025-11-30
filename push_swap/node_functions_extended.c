/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_functions_extended.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 12:56:33 by advorace          #+#    #+#             */
/*   Updated: 2025/11/30 12:56:43 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_free(t_stack *lst)
{
	t_stack	*tmp;

	while (lst)
	{
		tmp = (lst)->next;
		free(lst);
		lst = tmp;
	}
}

int	stack_len(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		++i;
	}
	return (i);
}
