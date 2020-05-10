#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int w, h;

	fscanf(f, "%d%d", &w, &h);
	fprintf(q, "%I64d", (long long)w * (w + 1) * h * (h + 1) / 4);
	return 0;
}
