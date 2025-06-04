#include "../libft.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *num = malloc(sizeof(int));
    if (!num)
        return (1);
    *num = 42;

    t_list *node = ft_lstnew(num);
    if (!node)
    {
        free(num);
        return (1);
    }

    printf("Node content: %d\n", *(int *)(node->content));
    printf("Node next: %p\n", (void *)node->next);

    // Free memory
    free(node->content);
    free(node);

    return (0);
}