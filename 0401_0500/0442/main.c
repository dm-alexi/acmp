#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int getword(FILE *f, char *s)
{
	char c;
	int i = 1;
	static int tag = 0;

	if (tag)
		s[0] = '<';
	else
		while (isspace(s[0] = getc(f)));
	if (s[0] == EOF)
		return EOF;
	if (s[0] == '<')
	{
		while ((s[i++] = getc(f)) != '>');
		s[i] = '\0';
		tag = 0;
		return 0;
	}
	while ((c = getc(f)) != '<' && c != EOF)
		if (!isspace(c))
			++i;
	tag = (c == '<');
	return i;
}

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	char s[5001];
	int p[50] = {0}, n, *fnt, k = 0, l = 16;

	fnt = (int*)malloc(sizeof(int) * l);
	fnt[k] = 10;
	while ((n = getword(f, s)) != EOF)
	{
		if (n > 0)
			p[fnt[k] - 1] += n;
		else if(!strncmp(s, "<font size=\"", 12))
		{
			fnt[k + 1] = (s[12] == '+' || s[12] == '-') ? fnt[k] + atoi(s + 12) : atoi(s + 12);
			if (++k == l - 1)
				l *= 2, fnt = (int*)realloc(fnt, sizeof(int) * l);
		}
		else if(!strcmp(s, "</font>"))
            --k;
	}
	for (int i = 0; i < 50; ++i)
		if (p[i])
			fprintf(q, "%d %d\n", i + 1, p[i]);
	return 0;
}
