#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, s = 0;
	char c;

	fscanf(f, "%d", &n);
	for (int i = 1, u = 1; s + u < n; ++i)
		s += u, u += i + 1< 10 ? 1 : i + 1 < 100 ? 2 : 3;
	n -= s;
	if (n < 10)
		c = n + '0';
	else if (n < 190)
	{
		n -= 10;
		c = n % 2 ? n % 20 / 2 + '0' : n / 20 + '1';
	}
	else
	{
		n -= 190;
		c = n % 3 == 0 ? '1' : n % 3 == 1 ? n / 30 + '0' : n % 30 / 3 + '0';
	}
	putc(c, q);
	return 0;
}
