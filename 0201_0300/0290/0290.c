#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, m, nb, mb, p = 0;
	char **base, **t;

	fscanf(f, "%d%d", &nb, &mb);
	base = (char**)malloc(sizeof(char*) * nb);
	for (int i = 0; i < nb; ++i)
	{
		base[i] = (char*)malloc(mb);
		fscanf(f, "%s\n", base[i]);
	}
	fscanf(f, "%d%d\n", &n, &m);
	t = (char**)malloc(sizeof(char*) * n);
	for (int i = 0; i < n; ++i)
	{
		t[i] = (char*)malloc(m);
		fscanf(f, "%s\n", t[i]);
	}
	for (int i = 0; i < n - nb + 1; ++i)
		for (int j = 0; j < m - mb + 1; ++j)
		{
			int r = 1;
			for (int k = 0; r && k < nb; ++k)
				for (int l = 0; r && l < mb; ++l)
					if (base[k][l] == '#' && t[i + k][j + l] == '.')
						r = 0;
			p += r;
		}
	fprintf(q, "%d", p);
	return 0;
}
