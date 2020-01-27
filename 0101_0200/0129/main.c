#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	short n, m, *last, *st, *s, *t;

	fscanf(f, "%hd%hd", &n, &m);
	t = (short*)malloc(sizeof(short) * n * m);
	last = s = st = (short*)malloc(sizeof(short) * n * m);
	for (int i = 0; i < n * m; ++i)
	{
		fscanf(f, "%hd", t + i);
		if (--t[i] == 0)
			*last++ = i;
	}
	while (s < last)
	{
        if (*s % m && t[*s - 1] < 0)
			*last++ = *s - 1, t[*s - 1] = t[*s] + 1;
		if ((*s + 1) % m && t[*s + 1] < 0)
			*last++ = *s + 1, t[*s + 1] = t[*s] + 1;
		if (*s / m && t[*s - m] < 0)
			*last++ = *s - m, t[*s - m] = t[*s] + 1;
		if (*s / m < n - 1 && t[*s + m] < 0)
			*last++ = *s + m, t[*s + m] = t[*s] + 1;
		++s;
	}
	for (int i = 0; i < n * m; ++i)
		fprintf(q, "%d%c", t[i], (i + 1) % m ? ' ' : '\n');
    return 0;
}
