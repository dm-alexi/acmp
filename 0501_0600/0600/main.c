#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n;
	char s[30001];

	fscanf(f, "%d", &n);
	while (n--)
	{
		fscanf(f, "%s", s);
		int i = 0, a = 0, b = 0, c = 0;
		while(s[i] == '0')
			++i, ++a;
		while(s[i] == '1')
			++i, ++b;
		while(s[i] == '2')
			++i, ++c;
		fprintf(q, !s[i] && a == b && a == c ? "YES\n" : "NO\n");
	}
	return 0;
}
