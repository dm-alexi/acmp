#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int h, m, s, d, a, b, c, t;

	fscanf(f, "%d:%d:%d", &h, &m, &s);
	t = fscanf(f, "%d:%d:%d", &a, &b, &c);
	if (t == 1)
		s += a;
	else if (t == 2)
		m += a, s += b;
	else
		h += a, m += b, s += c;
	m += s / 60, s %= 60;
	h += m / 60, m %= 60;
	d = h / 24, h %= 24;
	fprintf(q, d ? "%02d:%02d:%02d+%d days" : "%02d:%02d:%02d", h, m, s, d);
	return 0;
}
