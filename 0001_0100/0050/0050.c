#include <stdio.h>
#include <string.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int i, j, ls, lt, n = 0;
	char s[1001], t[2000];

	fscanf(f, "%s%s", s, t);
	ls = strlen(s);
	lt = strlen(t);
	memcpy(t + lt, t, lt + 1);
	for (i = 0; i < ls - lt + 1; ++i)
		for (j = 0; j < lt; ++j)
			if (!strncmp(s + i, t + j, lt) && ++n)
				break;
	fprintf(q, "%d", n);
	return 0;
}
