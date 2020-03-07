#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	long long a = 0;
	int x;
	char s[81], *t;

	fscanf(f, "%s\n%d", s, &x);
	t = s;
	while (*t)
	{
		long long c = 1, tmp;
		if (*t == '-' || *t == '+')
			c = (*t++ == '-' ? -1 : 1);
		if (isdigit(*t))
			tmp = strtol(t, &t, 10);
		else tmp = 1;
		if (*t == '^' && ++t)
		{
			while ((*t)-- > '1')
				c *= tmp;
			++t;
		}
		c *= tmp;
		if (*t == '*')
			++t;
		if (*t == 'x')
		{
			if (*(t + 1) == '^' && (t += 2))
				while ((*t)-- > '1')
					c *= x;
			c *= x;
			++t;
		}
		a += c;
	}
	fprintf(q, "%I64d", a);
	return 0;
}
