#include <stdio.h>
#include <string.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, r, l, max, min, b;
	char s[200001];

	fscanf(f, "%s", s);
	r = n = strlen(s);
	max = min = s[0];
	for (int i = 0; i < n; ++i)
		if (s[i] > max)
			max = s[i];
		else if (s[i] < min)
			min = s[i];
	if (min < max)
	{
		for (l = 0; s[l] != min && s[l] != max; ++l);
		for (int i = 0; i < n; ++i)
			if (s[i] == min || s[i] == max)
			{
				if (s[i] != s[l] && i - l < r)
					r = i - l, b = l;
				l = i;
			}
		fprintf(q, "%.*s", r + 1, s + b);
	}
	else
		putc(min, q);
	return 0;
}
