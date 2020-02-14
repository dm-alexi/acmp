#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, i = 1;
	char s[64];

	fscanf(f, "%d", &n);
	if (n < 21)
	{
		if (n < 12)
			--n;
		else if (n == 12)
			n = 22;
		else if (n == 20)
			n = 111;
		else
			n = 30 + (n - 13) * 10 + (n + 1) % 2;
		fprintf(q, "%d", n);
	}
	else
	{
		n -= 21;
		s[0] = n % 8 + '2';
		for (char c = '0' + n % 2; i < n / 8 + 3; ++i)
			s[i] = c;
		s[i] = '\0';
		fprintf(q, "%s", s);
	}
    return 0;
}
