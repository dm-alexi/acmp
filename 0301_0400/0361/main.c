#include <stdio.h>
#include <string.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int d;
	char s[101];

	fscanf(f, "%s", s);
	d = 0;
	for (int i = 0, n = strlen(s), k; d < n - i; ++i)
		if ((k = strrchr(s, s[i]) - s - i) > d)
			d = k;
	fprintf(q, "%d", d);
	return 0;
}
