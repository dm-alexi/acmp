#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, k;
	char s[1001];

	fscanf(f, "%d", &n);
	while (n--)
	{
		fscanf(f, "%s", s);
		k = 0;
		for (char *t = s + strlen(s) - 3; t > s; *t = '\0', t -= 3)
			k += strtol(t, NULL, 2);
		k += strtol(s, NULL, 2);
		fprintf(q, k % 7 ? "No\n" : "Yes\n");
	}
	return 0;
}
