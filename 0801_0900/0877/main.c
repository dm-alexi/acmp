#include <stdio.h>
#include <string.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n;
	char s[251], name[230];

	fscanf(f, "%s%s%s%s", s, name, s, s);
	n = strlen(name);
	for (int i = 0, k; fscanf(f, "%s %[^\n]\n", s, s) && (strncmp(s, name, n) || strcmp(s + n, " signed off")); ++i)
	{
		if (s[(k = (strlen(s) - 1))] == '.')
			s[k] = ',';
		else if (s[k] != '!' && s[k] != '?')
			s[++k] = ',', s[++k] = '\0';
		fprintf(q, "\"%s\" --- skazal %s.\n", s, i % 2 ? name : "Fedya");
	}
	return 0;
}
