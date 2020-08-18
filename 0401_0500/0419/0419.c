#include <stdio.h>
#include <ctype.h>
#include <string.h>

int delAt(char *s, int n, int k)
{
	char c = s[k];
	int r = 1;

	memmove(s + k, s + k + 1, n - k);
	for (int i = 0; r && i < (n - 1) / 2; ++i)
		if (s[i] != s[n - 2 - i])
			r = 0;
	if (!r)
		memmove(s + k + 1, s + k, n - k), s[k] = c;
	return r;
}

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
	if (!r && s[k + 1] == s[n - 1 - k])
		r = delAt(s, n, k);
	if (!r && s[k] == s[n - 2 - k])
		r = delAt(s, n, n - k - 1);
	fprintf(q, r ? "YES\n%s" : "NO", s);
	return 0;
}
