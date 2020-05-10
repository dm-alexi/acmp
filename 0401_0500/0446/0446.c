#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, m, r = 1;
	char *s, c;

	fscanf(f, "%d%d", &n, &m);
	s = (char*)malloc(n * m);
	for (int i = 0; i < n * m; ++i)
	{
		while (isspace(c = getc(f)));
		s[i] = (c == 'R' ? 4 : c == 'G' ? 2 : c == 'B' ? 1 : 0);
	}
	for (int i = 0, d; r && i < n * m; ++i)
	{
		fscanf(f, "%d", &d);
		if (s[i] && !(s[i] & d))
			r = 0;
	}
	fprintf(q, r ? "YES" : "NO");
	return 0;
}
