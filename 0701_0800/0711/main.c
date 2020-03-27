#include <stdio.h>
#include <string.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, m, d;
	char s[256], t[256];

	fscanf(f, "%d%d", &n, &m);
	d = 1000 * m + 1;
	while (n--)
	{
		int k = 0;
		fscanf(f, "%s", t);
		for (int i = 0, a; i < m; ++i)
			fscanf(f, "%d", &a), k += a;
		if (k < d)
			d = k, strcpy(s, t);
	}
	fprintf(q, "%s", s);
	return 0;
}
