#include <stdio.h>
#include <stdlib.h>

int gcd(int m, int n)
{
	while (n && m)
		if (n > m)
			n %= m;
		else
			m %= n;
	return n + m;
}

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, *p, *t, j;
	long long r = 1;

	fscanf(f, "%d", &n);
	if (n > 1)
	{
		p = (int*)malloc(sizeof(int) * n);
		t = (int*)malloc(sizeof(int) * n);
		for (int i = 0; i < n; ++i)
		{
			fscanf(f, "%d", &j);
			p[i] = j - 1, t[i] = 1;
		}
		for (int i = 0; i < n; ++i)
		{
			if ((j = p[i]) != i)
				while (++t[i] && p[j] != i)
					j = p[j];
		}
		r = t[0] * t[1] / gcd(t[0], t[1]);
		for (int i = 2; i < n; ++i)
			r = r * t[i] / gcd(r, t[i]);
	}
	fprintf(q, "%I64d", r);
	return 0;
}
