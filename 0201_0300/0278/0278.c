#include <stdio.h>
#include <string.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int r = 1;
	char s[262145], t[262145], *c = t;

	fscanf(f, "%s%s", s, t);
	for (char *k = s; r && *k; ++k)
		if ((r = ((c = (strchr(c, *k))) != NULL)))
			++c;
	fprintf(q, r ? "YES" : "NO");
	return 0;
}
