#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fsort(char *s, int up)
{
	if (*s == '-')
		return -fsort(s + 1, !up);
	int n = strlen(s);
	for (int i = 0; i < n; ++i)
	{
		int perm = 0;
		for (int j = 0; j < n - i - 1; ++j)
			if ((int)(s[j] < s[j + 1]) ^ up)
				s[j] ^= s[j + 1] ^= s[j] ^= s[j + 1], perm = 1;
		if (!perm)
			break;
	}
	if (up && n > 1)
	{
		char *t = s;
		while(*(++t) == '0');
		*s = *t, *t = '0';
	}
	return atoi(s);
}

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int a, b;
	char s[11], t[11];

	fscanf(f, "%s%s", s, t);
	fprintf(q, "%d", fsort(s, 0) - fsort(t, 1));
	return 0;
}
