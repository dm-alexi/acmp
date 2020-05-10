#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, k = 0;
	char *s;

	fscanf(f, "%d", &n);
	s = (char*)malloc(n * n + 1);
	for (int i = 0; i < n; ++i)
		fscanf(f, "%s", s + i * n);
	for (int i = 0; i < n * n; ++i)
		k += (s[i] == 'C');
	k = k / 2 + 1;
	for (int i = 0; i < n; ++i, putc('\n', q))
		for (int j = 0; j < n; ++j, putc(k ? '1' : '2', q))
			if (k && s[i * n + j] == 'C')
				--k;
	return 0;
}
