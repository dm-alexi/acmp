#include <stdio.h>
#include <stdlib.h>

void add(int *p, int k, int w, int h, int step, int *que, int *r)
{
	if (k % w > 0 && p[k - 1] == 0)
		p[k - 1] = step, que[(*r)++] = k - 1;
	if (k % w < w - 1 && p[k + 1] == 0)
		p[k + 1] = step, que[(*r)++] = k + 1;
	if (k / w > 0 && p[k - w] == 0)
		p[k - w] = step, que[(*r)++] = k - w;
	if (k / w < h - 1 && p[k + w] == 0)
		p[k + w] = step, que[(*r)++] = k + w;
}

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int w, h, *p, *que, n;
	char *s;

	fscanf(f, "%d%d", &w, &h);
	w += 2, h += 2;
	n = w * h;
	p = (int*)calloc(n, sizeof(int));
	s = (char*)malloc(w);
	for (int i = 1; i < h - 1; ++i)
	{
		fscanf(f, "%s\n", s);
		for (int j = 1; j < w - 1; ++j)
			if (s[j - 1] == 'X')
				p[i * w + j] = -1, --n;
	}
	que = (int*)malloc(sizeof(int) * n);
	for (int x1, y1, x2, y2; fscanf(f, "%d%d%d%d", &x1, &y1, &x2, &y2) && x1;)
	{
		int l = 0, r = 0, res;
		if (!(res = (x1 == x2 && abs(y1 - y2) == 1) || (y1 == y2 && abs(x1 - x2) == 1)))
		{
			add(p, y1 * w + x1, w, h, 1, que, &r);
			while (l < r)
			{
				n = que[l++];
				if ((abs(y2 * w + x2 - n) == 1 || abs(y2 * w + x2 - n) == w) && (res = p[n] + 1))
					break;
				add(p, n, w, h, p[n] + 1, que, &r);
			}
			for (int i = 0; i < w * h; ++i)
				if (p[i] > 0)
					p[i] = 0;
		}
		fprintf(q, "%d\n", res);
	}
	return 0;
}
