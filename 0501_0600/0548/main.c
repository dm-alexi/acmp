#include <stdio.h>
#include <string.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	char s[257], t[257], *a, *b;

	fscanf(f, "%s%s", s, t);
	for (a = s, b = t; *a && *b;)
		if (*a < *b)
			putc(*a++, q);
		else if (*a > *b)
			putc(*b++, q);
		else
		{
			char *i = a + 1, *j = b + 1;
			while (*i && *j && *i == *j)
				++i, ++j;
			putc(*i && (!*j || *i < *j) ? *a++ : *b++, q);
		}
	fprintf(q, "%s", *a ? a : b);
	return 0;
}
