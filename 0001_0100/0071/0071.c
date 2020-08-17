#include <stdio.h>
#define abs(x) (((x) > 0) ? (x) : -(x))

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, s = 0, p[18];

	fscanf(f, "%d", &n);
	for (int i = 0; i < n; ++i)
	{
		fscanf(f, "%d", p + i);
		s += p[i];
	}
	for (int i = 1, m = 1 << (n - 1); s && i < m; ++i)
	{
		int k = p[0], t = i;
		for (int j = 1; j < n; ++j)
			k += t & 1 ? -p[j] : p[j], t >>= 1;
		if (abs(k) < s)
			s = abs(k);
	}
	fprintf(q, "%d", s);
	return 0;
}