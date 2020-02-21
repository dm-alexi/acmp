#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	char *s = (char*)malloc(53), *t = (char*)malloc(53), *k;
	int n, a, b, c, d, m = 1441;

	fscanf(f, "%d", &n);
	while (n--)
	{
		int i = 1;
		while (getc(f) != '"');
		t[0] = '"';
		while ((t[i++] = getc(f)) != '"');
		t[i] = '\0';
		fscanf(f, "%d:%d %d:%d", &a, &b, &c, &d);
		d += (c - a) * 60 - b;
		if (d <= 0)
			d += 1440;
		if (d < m)
			m = d, k = t, t = s, s = k;
	}
	fprintf(q, "The fastest train is %s.\nIts speed is %d km/h, approximately.", s, (int)(650.0 * 60 / m + 0.5));
	return 0;
}
