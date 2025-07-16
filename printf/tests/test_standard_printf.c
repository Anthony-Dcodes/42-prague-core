#include <stdio.h>
#include <limits.h>

int main(void)
{
	int count;
	int x = 42;
	int *ptr = &x;

	printf("\n========== STANDARD PRINTF TEST ==========\n");

	// %c tests
	count = printf("Char test: %c\n", 'A');
	printf("Return count: %d\n", count);
	count = printf("Char null test: %cEND\n", '\0');
	printf("Return count: %d\n", count);
	count = printf("First char test: %c, second char test: %c\n", 'A', 'B');
	printf("Return count: %d\n", count);

	// %s tests
	count = printf("String test: %s\n", "Hello, World!");
	printf("Return count: %d\n", count);
	count = printf("Empty string test: %s\n", "");
	printf("Return count: %d\n", count);
	count = printf("Null string test: %s\n", (char *)NULL);
	printf("Return count: %d\n", count);

	// %p tests
	count = printf("Pointer test: %p\n", ptr);
	printf("Return count: %d\n", count);
	count = printf("Null pointer test: %p\n", NULL);
	printf("Return count: %d\n", count);

	// %d and %i tests
	count = printf("Decimal zero: %d\n", 0);
	printf("Return count: %d\n", count);
	count = printf("Decimal positive: %d\n", 12345);
	printf("Return count: %d\n", count);
	count = printf("Decimal negative: %d\n", -12345);
	printf("Return count: %d\n", count);
	count = printf("Decimal INT_MAX: %d\n", INT_MAX);
	printf("Return count: %d\n", count);
	count = printf("Decimal INT_MIN: %d\n", INT_MIN);
	printf("Return count: %d\n", count);

	count = printf("Integer test: %i\n", 67890);
	printf("Return count: %d\n", count);

	// %u tests
	count = printf("Unsigned zero: %u\n", 0);
	printf("Return count: %d\n", count);
	count = printf("Unsigned normal: %u\n", 12345);
	printf("Return count: %d\n", count);
	count = printf("Unsigned max: %u\n", UINT_MAX);
	printf("Return count: %d\n", count);

	// %x and %X tests
	count = printf("Hex lower: %x\n", 0xBEEF);
	printf("Return count: %d\n", count);
	count = printf("Hex lower zero: %x\n", 0);
	printf("Return count: %d\n", count);
	count = printf("Hex upper: %X\n", 0xBEEF);
	printf("Return count: %d\n", count);
	count = printf("Hex upper zero: %X\n", 0);
	printf("Return count: %d\n", count);

	// Mixed test
	count = printf("Mixed: char: %c, str: %s, dec: %d, hex: %x, ptr: %p\n",
		'A', "Test", 42, 255, ptr);
	printf("Return count: %d\n", count);

	// %% tests
	count = printf("Percent test: %%\n");
	printf("Return count: %d\n", count);
	count = printf("Multiple percent: %%%% %%\n");
	printf("Return count: %d\n", count);

	// Unknown specifier
	count = printf("Unknown specifier: %q bla bla bla\n");
	printf("Return count: %d\n", count);
	printf("END OF TESTS");

	return 0;
}
