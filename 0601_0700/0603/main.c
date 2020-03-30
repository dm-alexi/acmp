#include <stdio.h>
#include <ctype.h>

int eq(char *s, char *t)
{
	for (int i = 0, j = 0; t[i]; ++i, ++j)
		if (isspace(t[i]) && (isspace(s[j])))
			while(isspace(s[j + 1]))
				++j;
		else if (t[i] != tolower(s[j]))
			return 0;
	return 1;
}

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int c, n = 0;
	char s[2001], t[101], *p = s;

	while((c = getc(f)) != '\n')
		t[n++] = tolower(c);
	t[n] = '\0';
	for (n = 0; (s[n] = getc(f)) != EOF; ++n);
	s[n] = '\0';
	while(*p)
	{
		if (eq(p, t))
			putc('@', q);
		putc(*p++, q);
		while (isspace(*p))
			putc(*p++, q);
	}
	return 0;
}
