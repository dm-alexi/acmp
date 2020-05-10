#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n;
	const char *s;

	fscanf(f,"%d", &n);
	if (n < 1 || n > 12)
		s = "Error";
	else if (n < 3 || n == 12)
		s = "Winter";
	else if (n < 6)
		s = "Spring";
	else if (n < 9)
		s = "Summer";
	else
		s = "Autumn";
	fprintf(q, "%s", s);
	return 0;
}
