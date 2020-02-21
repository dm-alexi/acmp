#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
	return *(int*)a - *(int*)b;
}

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, *p, d = 0, day[12] = {0, 14880, 28320, 43200, 57600, 72480, 86880, 101760, 116640, 131040, 145920, 160320};

	fscanf(f, "%d", &n);
	p = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; ++i)
	{
		char s[12];
		fscanf(f, "%s %s", s, s + 6);
		p[i] = day[(s[3] - '0') * 10 + s[4] - '0' - 1] + ((s[0] - '0') * 10 + s[1] - '0' - 1) * 480 + (s[7] - '0') * 60 + (s[9] - '0') * 10 + s[10] - '0';
	}
	qsort(p, n, sizeof(int), cmp);
	for (int i = 0; i < n; i += 2)
		d += p[i + 1] - p[i] + 1;
	fprintf(q, "%d:%02d", d / 60, d % 60);
	return 0;
}
