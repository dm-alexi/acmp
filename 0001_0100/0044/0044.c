#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int i, k = 0;
	char s[251];

	fscanf(f, "%s", s);
	for (i = 0; s[i + 4]; ++i)
		if((s[i] == '>' && s[i + 1] == '>' && s[i + 2] == '-' && s[i + 3] == '-' && s[i + 4] == '>')
		   || (s[i] == '<' && s[i + 1] == '-' && s[i + 2] == '-' && s[i + 3] == '<' && s[i + 4] == '<'))
			++k;
	fprintf(q, "%d", k);
	return 0;
}
