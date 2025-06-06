#include "../libft.h"
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	t_list	*a = ft_lstnew("first");
	t_list	*b = ft_lstnew("second");

	a->next = b;
	int	size = ft_lstsize(a);
	printf("List size: %d", size);

	free(a);
	free(b);
	return (0);
}
