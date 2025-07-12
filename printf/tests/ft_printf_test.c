/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 19:52:58 by advorace          #+#    #+#             */
/*   Updated: 2025/07/12 10:21:12 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <limits.h>  // for INT_MIN, INT_MAX, UINT_MAX

int main(void)
{
    char c = 'C';
    char *str = "Hey man ";
    char *empty_str = "";
    char *null_str = NULL;
    int pos_int = 42;
    int neg_int = -1002;
    unsigned int big_u = UINT_MAX;
    unsigned int zero_u = 0;
    int *ptr = &pos_int;

    ft_printf("\n========== CHAR ==========\n");
    ft_printf("Single char: %c\n", c);
    ft_printf("Char as space: %c\n", ' ');
    ft_printf("Char with ASCII 0: %c\n", '\0');  // note: this won't be visible but should count

    ft_printf("\n========== STRING ==========\n");
    ft_printf("Normal string: %s\n", str);
    ft_printf("Empty string: %s\n", empty_str);
    ft_printf("NULL string: %s\n", null_str);  // should print (null)

    ft_printf("\n========== POINTER ==========\n");
    ft_printf("Valid pointer: %p\n", ptr);
    ft_printf("Null pointer: %p\n", NULL);

    ft_printf("\n========== DECIMAL / INTEGER ==========\n");
    ft_printf("Positive i: %i\n", pos_int);
    ft_printf("Negative i: %i\n", neg_int);
    ft_printf("Zero i: %i\n", 0);
    ft_printf("INT_MAX: %i\n", INT_MAX);
    ft_printf("INT_MIN: %i\n", INT_MIN);

    ft_printf("\n========== DECIMAL d ==========\n");
    ft_printf("Positive d: %d\n", pos_int);
    ft_printf("Negative d: %d\n", neg_int);
    ft_printf("Zero d: %d\n", 0);
    ft_printf("INT_MAX: %d\n", INT_MAX);
    ft_printf("INT_MIN: %d\n", INT_MIN);

    ft_printf("\n========== UNSIGNED u ==========\n");
    ft_printf("Big unsigned: %u\n", big_u);
    ft_printf("Zero unsigned: %u\n", zero_u);

    ft_printf("\n========== HEXADECIMAL x/X ==========\n");
    ft_printf("Small number x: %x\n", 992);
    ft_printf("Negative number x: %x\n", -992);
    ft_printf("Zero x: %x\n", 0);
    ft_printf("Big unsigned x: %x\n", big_u);
    ft_printf("Small number X: %X\n", 992);
    ft_printf("Negative number X: %X\n", -992);
    ft_printf("Zero X: %X\n", 0);
    ft_printf("Big unsigned X: %X\n", big_u);

    ft_printf("\n========== PERCENT SIGN %% ==========\n");
    ft_printf("Just percent: %%\n");
    ft_printf("Double percent: %%%% done\n");
    ft_printf("Mixed text %% between text %% end\n");

    ft_printf("\n========== UNKNOWN SPECIFIER ==========\n");
    ft_printf("Unknown specifier: %q should print as %%q\n");

    return 0;
}

