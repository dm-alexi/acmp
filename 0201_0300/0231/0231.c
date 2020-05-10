#include <stdio.h>
#include <ctype.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int c, n = 0, i = 0;

	while (isalnum(c = getc(f)))
	{
		if (isdigit(c))
			n = n * 10 + c - '0';
		else if (n == 0)
		{
			putc(c, q);
			if (!(++i % 40))
				putc('\n', q);
		}
		else for (; n > 0; --n)
		{
			putc(c, q);
			if (!(++i % 40))
				putc('\n', q);
		}
	}
	return 0;
}
