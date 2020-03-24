#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int k, m, n;
	char *s;

	fscanf(f, "%d%d", &n, &m);
	k = m;
	s = (char*)malloc(m + 1);
	for (int i = 0, d; i < n; ++i)
	{
		fscanf(f, "%s", s);
		d = strchr(s, 'B') - strrchr(s, 'A') - 1;
		if (d < k)
			k = d;
	}
	fprintf(q, "%d", k);
	return 0;
}
