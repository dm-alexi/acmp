#include <stdio.h>
#include <string.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n;
	char s[600000], *m;

	fscanf(f, "%d\n", &n);
	fgets(s, 599999, f);
	n = strlen(s) - 1;
	while (s[n] == ' ' || s[n] == '\n')
		--n;
	s[n + 1] = '\0';
	m = strstr(s, " 1 ");
	if (m)
	{
		*m = '\0';
		fprintf(q, "%s ", m + 1);
	}
	else if (s[0] != '1' || s[1] != ' ')
	{
		s[n] = '\0';
		fprintf(q, "1 ");
	}
	fprintf(q, "%s", s);
	return 0;
}
