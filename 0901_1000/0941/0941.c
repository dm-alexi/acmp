#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	char s[21], t[21];

	fscanf(f, "%s%s", s, t);
	fprintf(q, "%I64d", strtoll(s, NULL, 3) + strtoll(t, NULL, 3));
	return 0;
}
