#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	char s[50001];
	int n, *p;

	fscanf(f, "%s", s);
	n = strlen(s);
	p = (int*)malloc(sizeof(int) * n);
	p[0] = 0;
	for (int i = 1, k = 0; i < n; ++i)
	{
		while (k > 0 && s[i] != s[k])
			k = p[k - 1];
		if (s[i] == s[k])
			++k;
		p[i] = k;
	}
	fprintf(q, "%d", n - p[n - 1]);
	return 0;
}
