#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	short *t, n, d = 0, ns;

	fscanf(f, "%hd", &n);
	ns = n * n;
	t = (short*)malloc(sizeof(short) * ns);
	for (short l = 0, s = 1; l <= n / 2; ++l)
	{
		for (int i = l; i < n - l; ++i)
			t[l * n + i] = s++;
		for (int i = l + 1; i < n - l; ++i)
			t[i * n + n - l - 1] = s++;
		for (int i = n - l - 2; i >= l; --i)
			t[(n - l - 1) * n + i] = s++;
		for (int i = n - l - 2; i > l; --i)
			t[i * n + l] = s++;
	}
	while (ns)
		++d, ns /= 10;
	for (int i = 0; i < n * n; ++i)
		fprintf(q, "%*hd%c", d, t[i], (i + 1) % n ? ' ' : '\n');
	return 0;
}
