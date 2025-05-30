/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 09:24:45 by advorace          #+#    #+#             */
/*   Updated: 2025/05/30 14:29:39 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>

int	main(void)
{
	char	test_chars[] = {'A', 'z', 'M', '9', '*', ' ', '\n', 'g', '1', '0'};
	int	num_tests = sizeof(test_chars) / sizeof(test_chars[0]);
	int	i = 0;

	while (i < num_tests)
	{
		char	c = test_chars[i];
		printf("ft_isalpha('%c') = %d\n", c, ft_isalpha(c));
		i++;
	}
	printf("\n");
	i = 0;
	while (i < num_tests)
	{
		char	c = test_chars[i];
		printf("ft_isdigit('%c') = %d\n", c, ft_isdigit(c));
		i++;
	}
	printf("\n");
	i = 0;
	while (i < num_tests)
	{
		char	c = test_chars[i];
		printf("ft_isalnum('%c') = %d\n", c, ft_isalnum(c));
		i++;
	}
	printf("\n");
	i = 0;
	while (i < num_tests)
	{
		char	c = test_chars[i];
		printf("ft_isascii('%c') = %d\n", c, ft_isascii(c));
		i++;
	}
	printf("\n");
	i = 0;
	while (i < num_tests)
	{
		char	c = test_chars[i];
		printf("ft_isprint('%c') = %d\n", c, ft_isprint(c));
		i++;
	}
	printf("\n");
	printf("ft_strlen(hey) = %zu\n", ft_strlen("hey"));
	printf("ft_strlen() = %zu\n", ft_strlen(""));
	printf("ft_strlen(Hello world!) = %zu\n", ft_strlen("Hello world!"));
	i = 0;
	char a[10];
	ft_memset(a, 0, sizeof(a));
	ft_memset(a, 9, 5);
	while ((unsigned int)i < sizeof(a))
	{
		printf("%d", a[i]);
		i++;
	}
	printf("\n");
	i = 0;
	char s[10] = "abcdefghi";
	ft_bzero(s, 4);
	while (i < 10)
	{
		printf("char s[10] = abcdefghi, after ft_bzero(s, 4) at index: %d now: %d\n", i, s[i]);
		i++;
	}
	printf("\n");
	i = 0;
	char dst[15] = "Hello THERE!";
	char src[25] = "Hello WORLD!";
	printf("%s", (char *)ft_memcpy(dst, src, ft_strlen(src) + 1));
	printf("\n");
	char dst1[15] = "Hello man!";
	char src1[15] = "OMG I SAW HIM!";
	printf("%s\n", (char *)ft_memmove(src1, dst1 + 6, 3));
	printf("%s\n", (char *)ft_memmove(src1, src1 + 6, 6));

	printf("\nTesting ft_strlcpy()");
	char dst2[10];
	size_t result = ft_strlcpy(dst2, "HEY bitch!", 6);
	printf("Copied string: %s\n", dst2);
	printf("Lenght of source: %zu\n", result);

	printf("\nTesting ft_strlcat()\n");
	char dst3[10] = "AAAAAAA";
	size_t result1 = ft_strlcat(dst3, "Hey man!", 6);
	printf("Copied string: %s\n", dst3);
	printf("Lenght of source: %zu\n", result1);

	printf("Testing ft_toupper:\n");
	printf("a -> %c\n", ft_toupper((unsigned char)97));
	printf("A -> %c\n", ft_toupper((unsigned char)65));

	printf("Testing ft_tolower:\n");
	printf("a -> %c\n", ft_tolower((unsigned char)97));
	printf("A -> %c\n", ft_tolower((unsigned char)65));

	printf("Testing ft_strchr:\n");
	printf("From hello find firs l: %s\n", ft_strchr("hello", 108));
	printf("From hello find firs l: %s\n", ft_strchr("hello", 0));

	printf("Testing ft_strchr:\n");
	printf("From hello find last l: %s\n", ft_strrchr("hello", 108));
	printf("Print nothing: %s\n", ft_strrchr("hello", 0));

	printf("Testing ft_strncmp:\n");
	printf("Compare Hello and Hello %d\n", ft_strncmp("Hello", "Hello", 8));
	printf("Compare Hello and hello %d\n", ft_strncmp("Hello", "hello", 8));
	printf("Compare hello and Hello %d\n", ft_strncmp("hello", "Hello", 8));

	printf("Testing ft_memchr\n");
	char str[] = "Hello world!";
	printf("Find o in: %s: %s\n", str, (char *)ft_memchr(str, 'o', sizeof(str)));
	printf("Find w in: %s: %s\n", str, (char *)ft_memchr(str, 'w', sizeof(str)));
	
	return (0);

}
