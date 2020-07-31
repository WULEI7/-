#include <stdio.h>
#define N 1010

int m, n;
int a[N][N];
 
int main()
{
    scanf("%d %d", &n, &m);
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for (j = m - 1; j >= 0; j--)
    {
        for (i = 0; i < n; i++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
