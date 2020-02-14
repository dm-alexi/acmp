#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double ap[26] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
double mp[26] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

int acmp(const void *a, const void *b)
{
	return ap[*((const char*)a) - 'a'] - ap[*((const char*)b) - 'a'] > 0 ? 1 : -1;
}

int mcmp(const void *a, const void *b)
{
	return mp[*((const char*)a) - 'a'] - mp[*((const char*)b) - 'a'] > 0 ? 1 : -1;
}

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, m;
	char *s, *res, alpha[] = "abcdefghijklmnopqrstuvwxyz", mes[] = "abcdefghijklmnopqrstuvwxyz";
	double d;

	fscanf(f, "%d%d\n", &n, &m);
	res = (char*)malloc(n);
    for (int i = 0; i < n; ++i)
		fscanf(f, "%c %lf\n", res + i, &d), ap[res[i] - 'a'] = d;
	qsort(alpha, 26, 1, acmp);
	s = (char*)malloc(m + 1);
	fscanf(f, "%s", s);
	for (int i = 0; i < m; ++i)
		mp[s[i] - 'a'] += 1;
	for (int i = 0; i < n; ++i)
		mp[i] /= m;
	qsort(mes, 26, 1, mcmp);
	for (int i = 0; i < n; ++i)
		fprintf(q, "%c\n", mes[strchr(alpha, res[i]) - alpha]);
	return 0;
}
