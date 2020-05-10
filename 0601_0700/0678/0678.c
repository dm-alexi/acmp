#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int a = 1;
	char s[51];

	fscanf(f, "%s", s);
	for (int i = 0; s[i]; ++i)
		if (s[i] == 'A' && a != 3)
			a = 3 - a;
		else if (s[i] == 'B' && a != 1)
			a = 5 - a;
		else if (s[i] == 'C' && a != 2)
			a = 4 - a;
	fprintf(q, "%d", a);
	return 0;
}
