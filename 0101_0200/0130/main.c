#include <stdio.h>

void fill(int m[64], int k)
{
	int st[64], *s, *last;

    for (int i = 0; i < 64; ++i)
		m[i] = -1;
	m[k] = 0;
	s = last = st;
	*last++ = k;
	while (s < last)
	{
        if (*s % 8 < 7 && *s / 8 < 6 && m[*s + 17] < 0)
			*last++ = *s + 17, m[*s + 17] = m[*s] + 1;
        if (*s % 8 < 6 && *s / 8 < 7 && m[*s + 10] < 0)
			*last++ = *s + 10, m[*s + 10] = m[*s] + 1;
		if (*s % 8 < 6 && *s / 8 && m[*s - 6] < 0)
			*last++ = *s - 6, m[*s - 6] = m[*s] + 1;
		if (*s % 8 < 7 && *s / 8 > 1 && m[*s - 15] < 0)
			*last++ = *s - 15, m[*s - 15] = m[*s] + 1;
        if (*s % 8 && *s / 8 > 1 && m[*s - 17] < 0)
			*last++ = *s - 17, m[*s - 17] = m[*s] + 1;
        if (*s % 8 > 1 && *s / 8 && m[*s - 10] < 0)
			*last++ = *s - 10, m[*s - 10] = m[*s] + 1;
		if (*s % 8 > 1 && *s / 8 < 7 && m[*s + 6] < 0)
			*last++ = *s + 6, m[*s + 6] = m[*s] + 1;
		if (*s % 8 && *s / 8 < 6 && m[*s + 15] < 0)
			*last++ = *s + 15, m[*s + 15] = m[*s] + 1;
		++s;
	}
}

int main()
{
    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
    int a[64] = {-1}, b[64] = {-1}, t, s = 8, k;
    char c;

    fscanf(f, "%c%d", &c, &t);
    fill(a, k = (c - 'a') * 8 + t - 1);
    fscanf(f, " %c%d", &c, &t);
    t = (c - 'a') * 8 + t - 1;
    if (a[t] % 2)
		fprintf(q, "-1");
	else
	{
		fill(b, t);
		for (int i = 0; i < 64; ++i)
			if (a[i] == b[i] && a[i] < s)
				s = a[i];
		fprintf(q, "%d", s);
	}
    return 0;
}
