/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 17:44:16 by advorace          #+#    #+#             */
/*   Updated: 2025/12/02 20:30:45 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"
# include <limits.h>

int		ft_atoi_safe(const char *nptr, int *out);
typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

/* Node operations */
t_stack	*stack_new(int num);
void	stack_add_back(t_stack **lst, t_stack *new);
t_stack	*stack_last(t_stack *lst);
void	stack_free(t_stack *lst);
int		stack_len(t_stack *lst);
int		error(t_stack **stack_a, t_stack **stack_b);
int		init_stack_a(t_stack **stack_a, int argc, char **argv);
t_stack	*stack_second_last(t_stack *lst);

/* Possible Stack operations */
void	swap(t_stack **stack);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	push(t_stack **src, t_stack **dest);
void	pa(t_stack **stack_b, t_stack **stack_a);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	rotate(t_stack **stack);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	reverse_rotate(t_stack **stack);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

/* Preprocessing / utilities */
int		duplicates_check(int argc, int *array);
int		sort_array(int n_elements, int array[]);
int		create_safe_array(int argc, char **argv, int *array);
void	print_stack(t_stack **stack, char *stack_name);

/* New sort algo*/
void	main_sort_new(t_stack **stack_a, t_stack **stack_b, int argc);
void	main_sort(t_stack **stack_a, t_stack **stack_b, int argc);

/* Sorting algo utils */
int		check_sorted(t_stack *stack_a, t_stack *stack_b);
void	sort_three(t_stack **stack_a);
int		find_min(t_stack *stack);
int		find_min_pos(t_stack *stack);
void	rotate_to_top(t_stack **stack, int pos, char stack_name);
int		find_first_index_of_range(t_stack *stack, int min, int max);
int		find_last_index_of_range(t_stack *stack, int min, int max);
int		determine_rotations(t_stack *stack, int min, int max);

#endif
