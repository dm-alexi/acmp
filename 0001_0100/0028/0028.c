#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int x1, y1, x2, y2, x, y;

	fscanf(f,"%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x, &y);
	if (x1 == x2)
		x = 2 * x1 - x;
	else y = 2 * y1 - y;
	fprintf(q, "%d %d", x, y);
	return 0;
}
