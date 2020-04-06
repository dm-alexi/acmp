#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, l[20] = {0}, r[20] = {0}, lp = 0, rp = 0, *p;
	char c;

	fscanf(f, "%c %d", &c, &n);
	for (int d = 1, k; n; n /= 3, d *= 3)
		if ((k = n % 3) == 1)
			r[rp++] = d;
		else if (k == 2)
			l[lp++] = d, n += 3;
	fprintf(q, "L:");
	p = c == 'L' ? l : r;
	for (int i = 0; p[i]; ++i)
		fprintf(q, "%d ", p[i]);
	fprintf(q, "\nR:");
	p = c == 'L' ? r : l;
	for (int i = 0; p[i]; ++i)
		fprintf(q, "%d ", p[i]);
	return 0;
}
