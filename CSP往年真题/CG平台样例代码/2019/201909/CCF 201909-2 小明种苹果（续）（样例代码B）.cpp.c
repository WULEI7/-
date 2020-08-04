#include <stdio.h>
int main()
{
    int i, j;
    int t = 0, d = 0, e = 0;
    int n, m;
    int sum;
    int x;
    int f[1010] = {0};
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &m);
        scanf("%d", &sum);
        for (j = 1; j < m; j++)
        {
            scanf("%d", &x);
            if (x <= 0)
            {
                sum = sum + x;
            }
            else
            {
                if (x < sum)
                {
                    f[i] = 1;
                    sum = x;
                }
            }
        }
        t += sum;
        d += f[i];
    }
    for (i = 1; i <= n; i++)
    {
        if (f[(i - 1) % n + 1] && f[(i) % n + 1] && f[(i + 1) % n + 1])
            e++;
    }
    printf("%d %d %d\n", t, d, e);
    return 0;
}
