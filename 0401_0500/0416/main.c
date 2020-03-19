#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	char s[25], c1, c2;
	int	i = 0;

	fscanf(f, "%c%c", &c1, &c2);
	if (c1 > 'b' && c2 > '1')
		s[i++] = c1 - 2, s[i++] = c2 - 1, s[i++] = '\n';
	if (c1 > 'b' && c2 < '8')
		s[i++] = c1 - 2, s[i++] = c2 + 1, s[i++] = '\n';
	if (c1 > 'a' && c2 > '2')
		s[i++] = c1 - 1, s[i++] = c2 - 2, s[i++] = '\n';
	if (c1 > 'a' && c2 < '7')
		s[i++] = c1 - 1, s[i++] = c2 + 2, s[i++] = '\n';
	if (c1 < 'h' && c2 > '2')
		s[i++] = c1 + 1, s[i++] = c2 - 2, s[i++] = '\n';
	if (c1 < 'h' && c2 < '7')
		s[i++] = c1 + 1, s[i++] = c2 + 2, s[i++] = '\n';
	if (c1 < 'g' && c2 > '1')
		s[i++] = c1 + 2, s[i++] = c2 - 1, s[i++] = '\n';
	if (c1 < 'g' && c2 < '8')
		s[i++] = c1 + 2, s[i++] = c2 + 1, s[i++] = '\n';
	s[i] = '\0';
	fprintf(q, "%s", s);
	return 0;
}
