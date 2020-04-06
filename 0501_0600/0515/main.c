#include <stdio.h>
#include <math.h>

typedef struct {int x, y;} dot;

double distance(dot a, dot b)
{
	return sqrt((double)((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)));
}

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n;
	dot a = {0, 0}, b;
	double s = 0;

	fscanf(f, "%d", &n);
	while (n--)
	{
		fscanf(f, "%d%d", &b.x, &b.y);
		s += distance(a, b);
		a = b;
	}
	fprintf(q, "%.3f", s + sqrt((double)(a.x * a.x + a.y * a.y)));
	return 0;
}
