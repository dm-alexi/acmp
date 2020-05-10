#include <stdio.h>
#include <string.h>
#include <ctype.h>

int upper(char *s)
{
	while (*s)
		if (isupper(*s++))
			return 1;
	return 0;
}

int conv(char *s, int n, char *t)
{
	if (strchr(s, '_'))
	{
		if (s[0] == '_' || s[n - 1] == '_' || upper(s) || strstr(s, "__"))
			return 0;
		*t++ = *s;
		while (*++s)
			if (*s != '_')
				*t++ = (*(s - 1) == '_' ? toupper(*s) : *s);
	}
	else
	{
		if (!*s || isupper(*s))
			return 0;
		while (*s)
			if (isupper(*s))
				*t++ = '_', *t++ = tolower(*s++);
			else
				*t++ = *s++;
	}
	*t = '\0';
	return 1;
}

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	char s[101], t[201];

	fscanf(f, "%s", s);
	fprintf(q, "%s", conv(s, strlen(s), t) ? t : "Error!");
	return 0;
}
