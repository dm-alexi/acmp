#include <stdio.h>
#include <math.h>
#define PI 3.14159

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int x1, y1, x2, y2, r, s;
	double sn, k, a;

	fscanf(f, "%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &r, &s);
	k = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) / 2;
	a = 2 * acos(k / r);
	sn = k >= r ? 2 * PI * r * r : r * r * (2 * PI - a + sin(a));
	fprintf(q, sn > s ? "YES" : "NO");
	return 0;
}
