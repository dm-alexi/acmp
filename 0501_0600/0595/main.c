#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, ans, *p, d = 0;
	char s[50001], t[50001];

	fscanf(f, "%s%s", t, s);
	if ((ans = ((n = strlen(s)) == strlen(t))))
	{
		p = (int*)malloc(sizeof(int) * n);
		p[0] = 0;
		for (int i = 1, k = 0; i < n; ++i)
		{
			while (k > 0 && s[i] != s[k])
				k = p[k - 1];
			if (s[i] == s[k])
				++k;
			p[i] = k;
		}
		for (int i = 0; i < n; ++i)
		{
			while (d > 0 && s[d] != t[i])
				d = p[d - 1];
			if (s[d] == t[i])
				++d;
		}
		for (int i = 0; ans && t[d + i]; ++i)
			if (s[d + i] != t[n - 1 - d - i])
				ans = 0;
	}
	fprintf(q, ans ? "Yes\n%d" : "No", n - d);
	return 0;
}
