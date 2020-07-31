#include <stdio.h>
#define N 1010

int n;
int a[N] = {0};

int main()
{
    scanf("%d", &n);
    int num, i;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &num);
        a[num]++;
        printf("%d ", a[num]);
    }

    return 0;
}
