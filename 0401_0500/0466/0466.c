#include <stdio.h>

int	func(int n)
{
	while (!(n & 1))
		n >>= 1;
	return n == 1 ? 1 : func(n / 2) + func(n / 2 + 1);
}

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n;

	fscanf(f, "%d", &n);
	fprintf(q, "%d", func(n));
	return 0;
}
