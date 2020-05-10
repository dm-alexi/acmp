#include <stdio.h>
#include <string.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int i, n;
	char s[252];

	fscanf(f, "%s", s);
	n = strlen(s);
	for (i = 0; i < n - 1 && s[i] >= s[i + 1]; ++i);
	if (i == n - 1)
		s[n - 2] = '\0';
	else
	{
		memmove(s + i, s + i + 1, n - i);
		if (i)
			--i;
		for (; i < n - 2 && s[i] >= s[i + 1]; ++i);
		memmove(s + i, s + i + 1, n - i - 1);
	}
	fprintf(q, s);
	return 0;
}
