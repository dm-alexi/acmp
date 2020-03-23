#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, k = 0;
	char s[20000];

	n = fread(s, 1, 20000, f);
	for (int i = 0; i < n; ++i)
	{
		if (s[i] == ' ')
			k += 4;
		else if (s[i] == '.')
			k += 5;
		else if (s[i] == ';')
			k += 7;
		else if (s[i] == ',')
			k += 2;
		else if (s[i] == '(' || s[i] == ')')
			++k;
		else if (strchr("+-='\"", s[i]))
			k += 3;
		else if (strchr("{}[]<>", s[i]))
			k += 8;
		else if (isdigit(s[i]))
			k += 13 - (s[i] - '0');
		else if (isupper(s[i]))
			k += 10 + (s[i] - 'A' + 1) / 10 + (s[i] - 'A' + 1) % 10;
		else if (islower(s[i]))
			k += (s[i] - 'a' + 1) / 10 + (s[i] - 'a' + 1) % 10;
	}
	fprintf(q, "%d", k);
	return 0;
}
