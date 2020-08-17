#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	char s[256], *d = " abcdefghijklmnopqrstuvwxyz";

	fscanf(f, "%s", s);
	for (int i = 0; s[i]; ++i)
		s[i] = d[(s[i] - (s[i] <= '9' ? '0' : 'A' - 10) - (i + 1) % 27 + 27) % 27];
	fprintf(q, s);
	return 0;
}
