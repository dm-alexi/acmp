#include <stdio.h>
#include <string.h>

char *find(char *s1, char *s2, int len)
{
	while (strncmp(s1, s2, len))
		++s1;
	return (s1);
}

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, m, k = 0;
	char s[101], *t;

	fscanf(f, "%d%d%s", &n, &m, s);
	t = s + n - m + 1;
	while (--t >= s)
		if (find(s, t, m) == t)
			++k;
	fprintf(q, "%d", k);
	return 0;
}
