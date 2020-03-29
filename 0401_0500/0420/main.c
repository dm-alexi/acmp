#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	char str[1001], *s, *t;

	fscanf(f, "%s", str);
	if (isupper(*(s = str)))
		while (*s)
		{
			int n = 1 + (islower(s[1]) != 0);
			if (s[n] == '0' || (s[n] == '1' && !isdigit(s[n + 1])))
				break;
			t = s + n;
			while (isdigit(*t))
				++t;
			if (!strncmp(s, t, islower(t[1]) ? 2 : n))
				break;
			s = t;
		}
	fprintf(q, *s ? "NO" : "YES");
	return 0;
}
