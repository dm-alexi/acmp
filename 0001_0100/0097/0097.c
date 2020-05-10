#include <stdio.h>
#include <stdlib.h>
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

typedef struct rect
{
	int x1, y1, x2, y2;
} rect;

int intersect(rect a, rect b)
{
	return (!(a.x1 > b.x2 || a.x2 < b.x1 || a.y1 > b.y2 || a.y2 < b.y1));
}

int check(int *m, int n, int k)
{
	m[k * n + k] = 0;
	for (int i = 0; i < n; ++i)
		if (m[k * n + i])
		{
			m[k * n + i] = m[i * n + k] = 0;
			check(m, n, i);
		}
	return 1;
}

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, x1, y1, x2, y2, r, *m;
	rect *s;

	fscanf(f, "%d", &n);
	s = (rect*)malloc(sizeof(rect) * n);
	m = (int*)calloc(n * n, sizeof(int));
	for (int i = 0; i < n; ++i)
	{
		fscanf(f, "%d%d%d%d%d", &x1, &y1, &x2, &y2, &r);
		s[i].x1 = MIN(x1, x2) - r;
		s[i].y1 = MIN(y1, y2) - r;
		s[i].x2 = MAX(x1, x2) + r;
		s[i].y2 = MAX(y1, y2) + r;
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
			if (intersect(s[i], s[j]))
				m[i * n + j] = m[j * n + i] = 1;
		m[i * n + i] = 1;
	}
	r = 0;
	for (int i = 0; i < n; ++i)
		if (m[i * n + i])
			r += check(m, n, i);
	fprintf(q, "%d", r);
	return 0;
}
