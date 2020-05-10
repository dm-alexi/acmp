#include <stdio.h>
#include <string.h>

int sq(int n)
{
	while(n > 9)
	{
		int a = 0;
		while (n > 0)
			a += n % 10, n /= 10;
		n = a;
	}
	return n;
}

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int l;
	char s[101], r = 0;

	fscanf(f, "%s", s);
	if ((l = strlen(s)) > 1)
	{
		int a = s[0] - '0', b = 0;
		for (int i = 1; i < l; ++i)
			b += s[i] - '0';
		r = (sq(a) == sq(b));
		for (int i = 1; !r && i < l; ++i)
			r = (sq(a += s[i] - '0') == sq(b -= s[i] - '0'));
	}
	fprintf(q, r ? "YES" : "NO");
	return 0;
}
