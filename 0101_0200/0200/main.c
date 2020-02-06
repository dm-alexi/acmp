#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, k, m[4] = {0}, p[4] = {0}, count[4] = {0}, j = 0, t;
    int prime[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

    fscanf(f, "%d%d", &n, &k);
    for (int i = 0; i < 25 && k > 1; ++i)
        if (k % prime[i] == 0)
        {
            while (k % prime[i] == 0)
                k /= prime[i], ++p[j];
            m[j++] = prime[i];
        }
	if (k > 1)
        m[j] = k, p[j++] = 1;
    for (int i = 0; i < j; ++i)
    {
        int l = m[i];
        while (n / l > 0)
            count[i] += n / l, l *= m[i];
        count[i] /= p[i];
    }
    t = count[0];
    for (int i = 1; i < j; ++i)
        if (count[i] < t)
            t = count[i];
    fprintf(q, "%d", t);
    return 0;
}
