#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, m, c = 3;
	long long s = 0;

	fscanf(f, "%d", &n);
	while (n-- && fscanf(f, "%d", &m))
		if (m)
			s += c++;
		else
			c = c > 6 ? c - 3 : 3;
	fprintf(q, "%I64d", s);
	return 0;
}
