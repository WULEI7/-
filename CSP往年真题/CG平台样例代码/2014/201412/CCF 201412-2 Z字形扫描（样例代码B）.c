#include <stdio.h>
#define N 1010

int n;
int a[N][N] ;

int main()
{
    scanf("%d", &n);
    int i,j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    int x, y;
    for( i = 0; i < 2*n-1;i++)
    {
        x = i<n?0:i-n+1;
        y=i<n?i:n-1;
        if(i & 1)
            for(j = x; j <= y; j++)
                printf("%d ",a[j][i-j]);
        else 
            for(j = x; j <= y; j++)
                printf("%d ",a[i-j][j]);
    }

    return 0;
}
