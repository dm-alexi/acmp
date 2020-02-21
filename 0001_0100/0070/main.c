#include <stdio.h>
#include <string.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n;
	char s[1001], t[1024] = "NO SOLUTION";

	fscanf(f, "%s%d", s, &n);
	if (n > 0)
	{
		t[0] = '\0';
		while (n-- && strlen(t) < 1023)
			strncat(t, s, 1023 - strlen(t));
	}
	else
	{
		n = -n;
		int i, ls = strlen(s), k = ls / n;
		if (!(ls % n))
		{
			for (i = 0; i < ls; i += k)
				if (strncmp(s, s + i, k))
					break;
			if (i == ls)
				strncpy(t, s, k), t[k] = '\0';
		}
	}
	fprintf(q, t);
	return 0;
}
