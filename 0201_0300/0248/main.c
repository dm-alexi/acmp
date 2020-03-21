#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int getword(char *a, char **d)
{
	char *tmp = a;

	while (isalpha(*tmp))
		++tmp;
	*d = (char*)malloc(tmp - a + 1);
	strncpy(*d, a, tmp - a);
	(*d)[tmp - a] = '\0';
	return tmp - a;
}

int process(char *d, int n)
{
	int up = isupper(*d), stop = 0;

    if (!strcmp(d, "A") || !strcmp(d, "a") || !strcmp(d, "An") || !strcmp(d, "an") || !strcmp(d, "The") || !strcmp(d, "the"))
		return 0;
	d[0] = tolower(d[0]);
	for (int i = 0; i < n; ++i)
		if (d[i] == 'c')
			d[i] = (d[i + 1] == 'e' || d[i + 1] == 'i' ? 's' : 'k');
	while (!stop && (stop = 1))
		for (int i = 0; i < n - 1; ++i)
			if (d[i] == d[i + 1])
			{
				stop = 0;
                if (d[i] == 'e')
					d[i] = 'i';
				else if (d[i] == 'o')
					d[i] = 'u';
				memmove(d + i + 1, d + i + 2, n - i - 1);
				--n;
			}
    if (n > 1 && d[n - 1] == 'e')
		d[--n] = '\0';
	if (up)
		d[0] = toupper(d[0]);
	return n;
}

void despace(char *t)
{
	int n = strlen(t);
	char *s;

	if (*(s = t) == ' ')
	{
		while (*s == ' ')
			++s;
		memmove(t, s, (n -= s - t) + 1);
	}
	if (*(s = t + n - 1) == ' ')
		while (*s == ' ')
			*s-- = '\0';
	for (int i = 1; i < n; ++i)
		if (t[i] == ' ' && t[i - 1] == ' ')
		{
			s = t + i;
			while (*s == ' ')
				++s;
			memmove(t + i, s, (n -= s - t - i) + 1);
		}
}

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n;
	char s[201], *a, *b, *d;

	s[fread(s, 1, 200, f)] = '\0';
	a = b = s;
	while (*a && !isalpha(*a))
		++a, ++b;
	while (*a)
	{
		a += (n = getword(a, &d));
		n = process(d, n);
		strncpy(b, d, n);
		b += n;
		free(d);
		while (*a && !isalpha(*a))
			*b++ = *a++;
	}
	*b = '\0';
	despace(s);
	fprintf(q, "%s", s);
	return 0;
}
