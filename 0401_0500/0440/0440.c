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
	int t[5] = {0}, s = 0;
	dot m[5] = { {0, 0}, {25, 0}, {50, 0}, {75, 0}, {100, 0} }, a;

	for (int i = 0; i < 5; ++i)
	{
		fscanf(f, "%d%d", &a.x, &a.y);
		for (int j = 0; j < 5; ++j)
			if (!t[j] && (t[j] = (distance(m[j], a) <= 10)) && ++s)
				break;
	}
	fprintf(q, "%d", s);
	return 0;
}
