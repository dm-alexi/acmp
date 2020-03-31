#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int a, b;
	char s[7];

	fscanf(f, "%d%d%s", &a, &b, s);
	if ((s[0] == 'f' && b < a) || (s[0] == 'h' && b > a) || s[0] == 'a')
		a = b;
	fprintf(q, "%d", a);
	return 0;
}
