#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b)
{
	return *(char*)a - *(char*)b;
}

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	char s[21], t[21];
	int ans = 1, n;

	fscanf(f, "%s%s", s, t);
	for (int i = 0; ans && s[i]; ++i)
		if (s[i] == t[i])
			ans = 0;
	if (ans && (n = strlen(s)) == strlen(t))
	{
		qsort(s, n, 1, cmp);
		qsort(t, n, 1, cmp);
		ans = !strcmp(s, t);
	}
	fprintf(q, ans ? "YES" : "NO");
	return 0;
}
