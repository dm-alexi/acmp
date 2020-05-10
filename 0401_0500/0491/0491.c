#include <stdio.h>
#include <string.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, r = 1;
	char s[100001];

	fscanf(f, "%s", s);
	n = strlen(s);
	for (int i = 0; r && i < n / 2; ++i)
		if (s[i] != s[n - 1 - i])
			r = 0;
	if (r)
		for (int i = 1; r && i <= n / 2; ++i)
			if (s[i] != s[0])
				r = 0, s[n - 1] = '\0';
	fprintf(q, r ? "NO SOLUTION" : s);
	return 0;
}
