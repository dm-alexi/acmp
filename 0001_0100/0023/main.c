#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, s = 0;

	fscanf(f, "%d", &n);
	for (int i = 1; i <= n / 2; ++i)
		if (!(n % i))
			s += i;
	fprintf(q, "%d", s + n);
	return 0;
}
