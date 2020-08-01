#include <stdio.h>
#include <math.h>
int main()
{
    int a[5] = {0};
    int score = 0;
    int n;
    scanf("%d", &n);
    int x[1010], y[1010];
    int i, j, k;
    for (i = 1; i <= n; i++)
    {
        scanf("%d %d", &x[i], &y[i]);
    }
    for (i = 1; i <= n; i++)
    {
        score = 0;
        int t = 0;
        for (j = 1; j <= n; j++)
        {
            if (i == j)
                continue;
            if (x[i] == x[j] && abs(y[i] - y[j]) == 1 || y[i] == y[j] && abs(x[i] - x[j]) == 1)
            {
                t++;
                if (t == 4)
                    break;
            }
        }
        if (t == 4)
        {
            for (k = 1; k <= n; k++)
            {
                if (k == i)
                    continue;
                if (abs(x[i] - x[k]) == 1 && abs(y[i] - y[k]) == 1)
                    score++;
                if (score == 4)
                    break;
            }
            a[score]++;
        }
    }
    for (i = 0; i < 5; i++)
    {
        printf("%d\n", a[i]);
    }
}

