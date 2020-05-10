#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	char s[41], t[41];
	int k = 0;

	fscanf(f, "%s%s", s, t);
	if (!strstr(s, t))
		for (k = 0; k < 25; ++k)
		{
			for (int i = 0; t[i]; ++i)
				t[i] = (t[i] - 'A' + 1) % 26 + 'A';
			if (strstr(s, t))
			{
				for (int j = 0; s[j]; ++j)
					s[j] = (s[j] - 'A' + 25 - k) % 26 + 'A';
				break;
			}
		}
	fprintf(q, "%s", k == 25 ? "IMPOSSIBLE" : s);
	return 0;
}
