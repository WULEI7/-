#include<stdio.h>
int f(int x)
{
    if(x%7==0) return 1;
    int m=x;
    while(m!=0)
    {
        if(m%10==7) return 1;
        m=m/10;
    }
    return 0;
}
int main()
{
    int a[4]={0};
    int n;
    scanf("%d",&n);
    int i=0,t=0;
    while(t<n)
    {
        i++;
        if(f(i)) a[(i-1)%4]++;
        else t++;
    }
    for(int i=0;i<4;i++)
    {
        printf("%d\n",a[i]);
    }
}

