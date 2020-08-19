#include <stdio.h>

int count(int *t, char *s)
{
    int r = 0;
    for (int i = 0; i < 3 && t[i]; s += t[i], ++i)
        if (t[i] == 4)
		{
			if (s[0] == s[1] && s[0] == s[2] && s[0] == s[3])
				r += 5;
			else if (s[0] == s[3] && s[1] == s[2])
				r += 4;
			else if ((s[0] == s[1] && s[0] == s[2]) || (s[0] == s[2] && s[0] == s[3]) || (s[1] == s[2] && s[1] == s[3]) ||
					(s[0] == s[1] && s[2] == s[3]) || (s[0] == s[2] && s[1] == s[3]))
				r += 3;
			else if (s[0] == s[2] || s[1] == s[3])
				r += 2;
		}
		else if (t[i] == 3)
		{
			if (s[0] == s[1] && s[0] == s[2])
				r += 3;
			else if (s[0] == s[1] || s[0] == s[2] || s[1] == s[2])
				r += 2;
		}
		else if (s[0] == s[1])
			r += 2;
	return r;
}

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	char s[8], *l = s;
	int m = 0, k, t = 0, types[5][3] = { {4, 3, 0}, {3, 4, 0}, {3, 2, 2}, {2, 3, 2}, {2, 2, 3} };

	fscanf(f, "%s", s);
	for (int i = 0; i < 5; ++i)
		if ((k = count(types[i], s)) > m)
			m = k, t = i;
	for (int i = 0; i < 3 && types[t][i]; ++i)
	{
		if (i)
			fprintf(q, "-");
		while (types[t][i]--)
			fprintf(q, "%c", *l++);
	}
	fprintf(q, "\n%d", m);
	return 0;
}
