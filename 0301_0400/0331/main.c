#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int h, m, a, b;

	fscanf(f, "%d:%d%d%d", &h, &m, &a, &b);
	h += a, m += b;
	if (m >= 60)
		m %= 60, ++h;
	h %= 24;
	fprintf(q, "%02d:%02d", h, m);
	return 0;
}
