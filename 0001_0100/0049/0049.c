#include <stdio.h>

void bord(char a, int *min, int *max)
{
	if (a >= '0' && a <= '9')
		*min = *max = a - '0';
	else if (a == '?')
		*min = 0, *max = 9;
	else *min = a - 'a', *max = a - 'a' + 3;
}

int both(char a, char b)
{
	int amin, amax, bmin, bmax;

	bord(a, &amin, &amax);
	bord(b, &bmin, &bmax);
	if (bmin > amin)
		amin = bmin;
	if (bmax < amax)
		amax = bmax;
	return amax - amin < 0 ? 0 : amax - amin + 1;
}

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	char s[10], p[10];
	int k = 1;

	fscanf(f, "%s%s", s, p);
	for (int i = 0; s[i]; ++i)
		k *= both(s[i], p[i]);
	fprintf(q, "%d", k);
	return 0;
}
