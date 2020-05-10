#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int h = 0, l = 0, k = 0;
	char c;

	while ((c = getc(f)) == '1' || c == '2')
		if (c == '1' && ++k > h)
			++h;
		else if (c == '2' && --k < l)
			--l;
	fprintf(q, "%d", h - l + 1);
	return 0;
}
