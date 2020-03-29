#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int k = -1, n = 0, r = 1, c;
	char s[100001];

	while ((c = getc(f)) != EOF)
		if (isalpha(c))
			s[n++] = tolower(c);
	s[n] = '\0';
	for (int i = 0; r && i < n / 2; ++i)
		if (s[i] != s[n - 1 - i])
			if (k == -1)
				k = i;
			else
				r = 0;
	if (r && k > -1)
		s[k] = s[n - k - 1];
	if (!r && (s[k + 1] == s[n - 1 - k] || s[k] == s[n - 2 - k]))
	{
		r = 1;
		if (s[k + 1] == s[n - 1 - k])
			memmove(s + k, s + k + 1, n - k);
		else
			memmove(s + n - k - 1, s + n - k, k + 1);
		--n;
		for (int i = 0; r && i < n / 2; ++i)
			if (s[i] != s[n - 1 - i])
				r = 0;
	}
	fprintf(q, r ? "YES\n%s" : "NO", s);
	return 0;
}
