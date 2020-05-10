#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int w, h;
	char *s, *t, c, p[5];

	fscanf(f, "%d%d", &w, &h);
	s = (char*)malloc(w * h);
	t = (char*)malloc(w * h);
	for (int i = 0; i < w * h; ++i)
	{
		while (isspace(c = getc(f)));
		s[i] = c - '0';
	}
	for (int i = 0; i < w * h; ++i)
	{
		while (isspace(c = getc(f)));
		t[i] = c - '0';
	}
	fscanf(f, "%s", p);
	for (int i = 0; i < w * h; ++i)
		s[i] = (!s[i] && !t[i] ? p[0] : !s[i] && t[i] ? p[1] : s[i] && !t[i] ? p[2] : p[3]);
	for (int i = 0; i < h * w; i += w)
		fprintf(q, "%.*s\n", w, s + i);
	return 0;
}
