#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	short *t, n, d = 0, ns;

	fscanf(f, "%hd", &n);
    ns = n * n;
    t = (short*)malloc(sizeof(short) * ns);
	for (int i = 1, x = 0, y = 0, v = 0; i <= ns; ++i)
	{
		t[x * n + y] = i;
		if (v)
		{
			if (y == n - 1)
				++x, v = !v;
			else if (x == 0)
				++y, v = !v;
			else
				--x, ++y;
		}
		else
		{
			if (x == n - 1)
				++y, v = !v;
			else if (y == 0)
				++x, v = !v;
			else
				++x, --y;
		}
	}
	while (ns)
		++d, ns /= 10;
	for (int i = 0; i < n * n; ++i)
		fprintf(q, "%*hd%c", d, t[i], (i + 1) % n ? ' ' : '\n');
    return 0;
}
