#include <stdio.h>
#include <string.h>

int cut(char *s)
{
	char *t;
	int n = strlen(s);

	if (!(t = strchr(s, '.')))
		return n;
	while (s[n - 1] == '0')
		--n;
	if (s[n - 1] == '.')
		--n;
	s[n] = '\0';
	return t - s;
}

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int sint, tint, r;
	char s[10001], t[10001];

	fscanf(f, "%s%s", s, t);
	if (s[0] == '-' && t[0] != '-')
		r = -1;
	else if (s[0] != '-' && t[0] == '-')
		r = 1;
	else if ((sint = cut(s)) == (tint = cut(t)))
		r = strcmp(s, t);
	else
		r = sint > tint ? 1 : -1;
	if (s[0] == '-' && t[0] == '-')
		r *= -1;
	putc(r ? (r > 0 ? '>' : '<') : '=', q);
	return 0;
}
