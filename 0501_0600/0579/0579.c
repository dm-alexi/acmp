#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, *p, ps = 0, ns = 0, pl = 0, nl = 0;

	fscanf(f, "%d", &n);
	p = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; ++i)
	{
		fscanf(f, "%d", p + i);
		if (p[i] > 0)
			ps += p[i], ++pl;
		else if (p[i] < 0)
			ns += -p[i], ++nl;
	}
	fprintf(q, "%d\n", ps >= ns ? pl : nl);
	for (int i = 0; i < n; ++i)
		if ((ps >= ns && p[i] > 0) || (ps < ns && p[i] < 0))
			fprintf(q, "%d ", i + 1);
	return 0;
}
