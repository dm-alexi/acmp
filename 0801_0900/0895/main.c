#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int p[9];
	char c;
	const char *t = "Draw";

	for (int i = 0; (c = getc(f)) != EOF;)
		if (c == 'X')
			p[i++] = 1;
		else if (c == 'O')
			p[i++] = -1;
		else if (c == '.')
			p[i++] = 0;
	if (p[0] + p[3] + p[6] == 3 || p[1] + p[4] + p[7] == 3 || p[2] + p[5] + p[8] == 3 || p[0] + p[4] + p[8] == 3 || p[2] + p[4] + p[6] == 3 ||
		p[0] + p[1] + p[2] == 3 || p[3] + p[4] + p[5] == 3 || p[6] + p[7] + p[8] == 3)
			t = "Win";
	else if (p[0] + p[3] + p[6] == -3 || p[1] + p[4] + p[7] == -3 || p[2] + p[5] + p[8] == -3 || p[0] + p[4] + p[8] == -3 || p[2] + p[4] + p[6] == -3 ||
		p[0] + p[1] + p[2] == -3 || p[3] + p[4] + p[5] == -3 || p[6] + p[7] + p[8] == -3)
			t = "Lose";
	fprintf(q, t);
	return 0;
}
