#include "push_swap.h"

static int	error(void)
{
	write(2, "Error\n", 6);
	return (0);
}

int main(int argc, char *argv[])
{
	int	i;
	int	num;
	t_stack	*stack_a;
	t_stack	*temp;

	i = 1;
	if (argc == 1)
		return (0);
	while (i < argc)
	{
		if (!ft_atoi_safe(argv[i], &num))
		{
			return (error());
		}
		if (i == 1)
			stack_a = stack_new(num);
		else
		{
			temp = stack_new(num);
			stack_add_back(&stack_a, temp);
		}
		++i;
	}
	temp = stack_a;
	ft_printf("Stack len: %d\n", stack_len(stack_a));
	while (temp)
	{
		ft_printf("%d\n", temp->value);
		temp = temp->next;
	}
	stack_free(stack_a);
	return (0);
}
