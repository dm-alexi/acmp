#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n = 0, p[100000], l = 2147483647, r = 0, i, k;
	char *s, *ans = "No";

	while (fscanf(f, "%d", p + n) == 1)
	{
		if (p[n] > r)
			r = p[n];
		if (p[n] < l)
			l = p[n];
		++n;
	}
	if (r == l)
		ans = "Yes";
	else if ((r - l) % (n - 1) == 0)
	{
		k = (r - l) / (n - 1);
		s = (char*)calloc(n, 1);
		for (i = 0; i < n; ++i)
			if ((p[i] - l) % k || s[(p[i] - l) / k]++)
				break;
		if (i == n)
			ans = "Yes";
	}
	fprintf(q, "%s", ans);
	return 0;
}
