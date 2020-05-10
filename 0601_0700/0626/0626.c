#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n;
	char s[100001], tab[26] = {0}, t[3];

	fscanf(f, "%d", &n);
	while (n--)
	{
		fscanf(f, "%s", t);
		tab[t[0] - 'a'] = t[1];
	}
	fscanf(f, "%s", s);
	for (int i = 1, j = 0, k = -1; s[i]; k = j, j = i++)
		while (j >= 0 && s[i] && tab[s[j] - 'a'] == s[i])
		{
			s[j] = s[i++] = ' ';
			j = k;
			while (j >= 0 && s[j] == ' ')
				--j;
			k = j - 1;
		}
	for (int i = 0; s[i]; ++i)
		if (s[i] != ' ')
			putc(s[i], q);
	putc('\n', q);
	return 0;
}
