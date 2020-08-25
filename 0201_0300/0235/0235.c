#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int t[101][101] = {{0}}, d[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} }, k = 0, x = 50, y = 50, dir = 0;
	char s[201];

	t[x][y] = 1;
	fscanf(f, "%s", s);
	for (char *c = s; *c && t[x][y] < 2; ++c)
	{
		if (*c == 'L')
			dir = (dir + 3) % 4;
		else if (*c == 'R')
			dir = (dir + 1) % 4;
		else
			x += d[dir][0], y += d[dir][1], ++t[x][y], ++k;
	}
    fprintf(q, "%d", t[x][y] > 1 ? k : -1);
	return 0;
}
