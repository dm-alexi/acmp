#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int x1, y1, x2, y2, xa, ya, xb, yb;

	fscanf(f,"%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &xa, &ya);
	if (x1 == x2)
		yb = ya, xb = 2 * x1 - xa;
	else yb = 2 * y1 - ya, xb = xa;
	fprintf(q, "%d %d", xb, yb);
	return 0;
}
