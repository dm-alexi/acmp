#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, m, p[30001] = {0}, k = 1, r, s, max = 0;

	fscanf(f, "%d%d", &n, &m);
	for (int i = 0, a; i < n; ++i)
	{
		fscanf(f, "%d", &a);
		++p[a];
		if (a > max)
			max = a;
	}
	while (p[k] == 0)
		++k;
	while (k < max)
	{
		r = k + 1;
		while (p[r] == 0)
			++r;
		if (m <= (r - k) * p[k])
		{
			s = k + m / p[k];
			m = 0;
			break;
		}
		m -= (r - k) * p[k];
		p[r] += p[k];
		k = r;
	}
	if (m)
		s = max + m / n;
	fprintf(q, "%d", s);
	return 0;
}
