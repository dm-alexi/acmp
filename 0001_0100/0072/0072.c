#include <stdio.h>
#include <string.h>

void rev(char *s)
{
	int n = strlen(s);

	for (int i = 0; i < n / 2; ++i)
		s[i] ^= s[n - 1 - i] ^= s[i] ^= s[n - 1 -i];
}

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	char s[81];
	int i, l, k;

	fscanf(f, "%s", s);
	l = strlen(s);
	for (k = l - 2 ; s[k] >= s[k + 1]; --k);
	for (i = l - 1; s[i] <= s[k]; --i);
	s[k] ^= s[i] ^= s[k] ^= s[i];
	rev(s + k + 1);
	fprintf(q, s);
	return 0;
}
