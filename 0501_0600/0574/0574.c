#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	char s[100001];
	int p[26] = {0}, r = 1;

	fscanf(f, "%s", s);
	for (int i = 0; s[i]; ++i)
		++p[s[i] - 'A'];
	fscanf(f, "%s", s);
	for (int i = 0; s[i]; ++i)
		--p[s[i] - 'A'];
	for (int i = 0; r && i < 26; ++i)
		r = !p[i];
	fprintf(q, r ? "YES" : "NO");
	return 0;
}
