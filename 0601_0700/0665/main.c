#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int h, m;

	fscanf(f, "%d:%d", &h, &m);
	if (m >= h % 10 * 10 + h / 10)
		h = (h + 1) % 24;
	if (h % 10 > 5)
		h += 10 - h % 10;
	fprintf(q, "%02d:%02d", h, h % 10 * 10 + h / 10);
	return 0;
}
