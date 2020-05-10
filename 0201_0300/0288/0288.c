#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int k = 0;
	char s[16385], *t;

	s[fread(s, 1, 16384, f)] = '\0';
	t = s;
	while (*t)
	{
		switch (*t)
		{
		case '\'':
			while (*++t != '\'');
			break;
		case '{':
			while (*++t != '}');
			++k;
			break;
		case '(':
			if (*(t + 1) == '*' && (t += 3) && ++k)
				while (!(*t == ')' && *(t - 1) == '*'))
					++t;
			break;
		case '/':
			if (*(t + 1) == '/' && ++k)
				while (*++t != '\n' && *(t + 1));
			break;
		}
		++t;
	}
	fprintf(q, "%d", k);
	return 0;
}
