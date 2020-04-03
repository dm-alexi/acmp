#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int p[26] = {0}, r;
	char s[51], t[51];

	fscanf(f, "%s%s", s, t);
	if ((r = (strlen(s) == strlen(t))))
	{
		for (int i = 0; s[i]; ++i)
			++p[tolower(s[i]) - 'a'], --p[tolower(t[i]) - 'a'];
		for (int i = 0; r && i < 26; ++i)
			r = !p[i];
	}
	fprintf(q, r ? "Yes" : "No");
	return 0;
}
