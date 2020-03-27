#include <stdio.h>
#include <string.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, k, d;
	char str[101001], t[101], *s = str;

	fscanf(f, "%d%d\n", &k, &n);
	while (n--)
	{
		fscanf(f, "%[^\n]\n", t);
		d = strlen(t);
		while (t[d - 1] == ' ')
			--d;
		if (d > k)
			break;
		memset(s, ' ', (k - d) / 2);
		strncpy(s + (k - d) / 2, t, d);
		memset(s + (k + d) / 2, ' ', k - (k + d) / 2);
		s[k] = '\n';
		s += k + 1;
	}
	*s = '\0';
	fprintf(q, "%s", n < 0 ? str : "Impossible.");
	return 0;
}
