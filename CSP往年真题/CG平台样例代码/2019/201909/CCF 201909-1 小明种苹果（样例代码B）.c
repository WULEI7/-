#include<stdio.h>
int main()
{
    int n,m;
    int sum;
    int temp;
    int t=0,k=0,p=0;
    scanf("%d%d",&n,&m);
    int i,j;
    for(i=1;i<=n;i++)
    {
        int sub=0;
        scanf("%d",&sum);
        for(j=1;j<=m;j++)
        {
            scanf("%d",&temp);
            sub-=temp;
            sum+=temp;
        }
        t+=sum;
        if(sub>p)
        {
            k=i;
            p=sub;
        }
    }
    printf("%d %d %d\n",t,k,p);
    return 0;
}
