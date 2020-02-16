#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int *p, k = 0, n, j;
	char s[20001] = {0};

	fscanf(f, "%d", &n);
	for (int i = 0, a; i < n; ++i)
	{
		fscanf(f, "%d", &a);
		if (!s[a + 10000])
			++k, s[a + 10000] = 1;
	}
	p = (int*)malloc(sizeof(int) * k);
	for (int i = 0, j = 0; i < 20001; ++i)
		if (s[i])
			p[j++] = i - 10000;
	if (k > 1)
		fprintf(q, "%d, ", p[0]);
	for (int i = 1; i < k - 1; ++i)
	{
		for (j = i; j < k && p[j] == p[j - 1] + 1; ++j)
			;
		if (j - i < 2 || (j - i == 2 && p[i] > -100 && p[i] < 1000))
			fprintf(q, "%d, ", p[i]);
		else
			fprintf(q, j == k ? "..., " : "..., %d, ", p[j - 1]), i = j - 1;
	}
	fprintf(q, "%d", p[k - 1]);
	return 0;
}
