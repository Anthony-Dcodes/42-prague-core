/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 16:56:23 by advorace          #+#    #+#             */
/*   Updated: 2025/09/11 17:30:12 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

// Allocates mem and returns a new node of list
t_stack	*stack_new(int num)
{
	t_stack	*elm;

	elm = malloc(sizeof(t_stack));
	if (!elm)
		return (NULL);
	elm->value = num;
	elm->next = NULL;
	return (elm);
}

// Add new to the back of lst
// Do nothing if either is NULL (garbage)
// If lst is empty set new as the first element of lst
void	stack_add_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = stack_last(*lst);
	last->next = new;
}

// Return the last element of lst
t_stack	*stack_last(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
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
