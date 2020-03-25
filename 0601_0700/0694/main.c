#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int a, b, st, fin, n;
	fscanf(f, "%d%d%d", &n, &a, &b);
	while (--n && a <= b)
	{
		fscanf(f, "%d%d", &st, &fin);
		if (st > a)
			a = st;
		if (fin < b)
			b = fin;
	}
	fprintf(q, a > b ? "NO" : "YES");
	return 0;
}
