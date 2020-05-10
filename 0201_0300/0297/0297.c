#include <stdio.h>
#include <string.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	char s[102];
	int n = 0;

	fscanf(f, "%s", s);
	for (int i = 0; s[i]; ++i)
		if (strchr("069", s[i]))
			++n;
		else if (s[i] == '8')
			n += 2;
	fprintf(q, "%d", n);
	return 0;
}
