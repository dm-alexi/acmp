#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int x1, y1, x2, y2;

	fscanf(f, "%d%d%d%d", &x1, &y1, &x2, &y2);
	x1 = abs(x1 - x2), y1 = abs(y1 - y2);
	fprintf(q, "%d", x1 == y1 ? 1 : x1 % 2 == y1 % 2 ? 2 : 0);
	return 0;
}
