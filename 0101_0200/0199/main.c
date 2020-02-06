#include <stdio.h>
#include <string.h>

const char *v = "IVXLCDM";
const int m[] = {1, 5, 10, 50, 100, 500, 1000};

int gcd(int m, int n)
{
    while (n && m)
        if (n > m)
            n %= m;
        else
			m %= n;
    return n + m;
}

int derome(char *s)
{
	int n = 0;

    for (int i = strlen(s) - 1; i >= 0; --i)
    {
        int k = strchr(v, s[i]) - v, g = strchr(v, s[i - 1]) - v;
        n += m[k];
        if (i && g < k)
			n -= m[g], --i;
    }
    return n;
}

char *rome(int n, char *s)
{
	int j = 0;
	for (int i = 6; i >= 0; --i)
	{
        if (n >= m[i])
        {
			for (int k = 0; k < n / m[i]; ++k)
                s[j++] = v[i];
            n %= m[i];
        }
        for (int k = 0; k < 6; k += 2)
			if (n > m[k] && n + m[k] >= m[i])
				s[j++] = v[k], s[j++] = v[i], n -= m[i] - m[k];
    }
    s[j] = '\0';
    return s;
}

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	char s[21], *t;
	int a, b, d = 0;

	fscanf(f, "%s", s);
	for (char *h = s; *h; ++h)
		if (*h == '/' && !d)
			++d, t = h;
		else if (!strchr(v, *h) && (d = -1))
			break;
	if (d != 1)
		fprintf(q, "ERROR");
	else
	{
		*t = '\0';
		a = derome(s), b = derome(t + 1), d = gcd(a, b);
		a /= d, b /= d;
		fprintf(q, "%s", rome(a, s));
		if (b > 1)
			fprintf(q, "/%s", rome(b, s));
	}
	return 0;
}
