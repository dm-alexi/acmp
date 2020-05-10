#include <stdio.h>
#include <string.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	char s[5], t[5];
	int b = 0, k = 0;

	fscanf(f, "%s%s", s, t);
	for (int i = 0; i < 4; ++i)
		if(s[i] == t[i])
			++b;
		else if(strchr(t, s[i]) != NULL)
			++k;
	fprintf(q, "%d %d", b, k);
	return 0;
}
