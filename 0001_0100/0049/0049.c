#include <stdio.h>

int count(int n)
{
	int s = 0;
	while (n)
		s++, n &= n - 1;
	return s;
}

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	char s[10], t[10];
	int k = 1, p[104];

	fscanf(f, "%s%s", s, t);
	for (int i = '0'; i <= '9'; ++i)
		p[i] = 1 << i - '0';
	for (int i = 'a'; i <= 'g'; ++i)
		p[i] = 15 << i - 'a';
	p['?'] = 1023;
	for (int i = 0; s[i] && k; ++i)
		k *= count(p[s[i]] & p[t[i]]);
	fprintf(q, "%d", k);
	return 0;
}
