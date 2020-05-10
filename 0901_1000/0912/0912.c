#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, p[100] = {0}, m = 0, c, r;

	fscanf(f, "%d", &n);
	for (int i = 0; i < n; ++i)
	{
		fscanf(f, "%d", &c);
		if (++p[c - 1] > m)
			m = p[c - 1], r = c;
		else if (p[c - 1] == m)
			r = 0;
	}
	fprintf(q, "%d", r);
	return 0;
}
