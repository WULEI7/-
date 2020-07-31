#include <stdio.h>
#include<math.h>
int main()
{
    int i;
    int n;
    int maxx, minn;
    double mid;
    int a[100010];
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    if (a[n] > a[1])
    {
        maxx = a[n];
        minn = a[1];
    }
    else
    {
        maxx = a[1];
        minn = a[n];
    }
    if (n % 2 == 0)
        mid = (a[n / 2] + a[n / 2 + 1]) / 2.0;
    else
        mid = a[n / 2 + 1];
    if (n % 2 == 0 && (abs(a[n / 2] + a[n / 2 + 1]) % 2) == 1)
        printf("%d %.1f %d\n", maxx, mid, minn);
    else
        printf("%d %.0f %d\n", maxx, mid, minn);
    return 0;
}
