#include <stdio.h>
#include <ctype.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n = 1;
	char s[256];

	fscanf(f, "%[^\n]", s);
	for (int i = 0, k; n > 0 && s[i]; ++i)
	{
		k = s[i] == '0' ? 2 : isdigit(s[i]) ? s[i] - '0' + 1 : isupper(s[i]) ? s[i] - 'A' + 11 : -1;
		if (k == -1 || k > n)
			n = k;
	}
	fprintf(q, "%d", n);
	return 0;
}
