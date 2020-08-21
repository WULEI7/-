#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;
int a[3][3];
int dep;
int maxx(int dep,int al,int pe);
int minn(int dep,int al,int pe);
int value()
{
    int s=0;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(a[i][j]==0)s++;
        }
    }
    if(a[0][1]==a[0][0]&&a[0][2]==a[0][0])
    {
        if(a[0][0]==1)return s+1;
        else if(a[0][0]==2)return -(s+1);
    }
    if(a[1][1]==a[1][0]&&a[1][2]==a[1][0])
    {
        if(a[1][0]==1)return s+1;
        else if(a[1][0]==2)return -(s+1);
    }
    if(a[2][1]==a[2][0]&&a[2][2]==a[2][0])
    {
        if(a[2][0]==1)return s+1;
        else if(a[2][0]==2)return -(s+1);
    }
    if(a[0][0]==a[1][0]&&a[0][0]==a[2][0])
    {
        if(a[0][0]==1)return s+1;
        else if(a[0][0]==2)return -(s+1);
    }
    if(a[0][1]==a[1][1]&&a[0][1]==a[2][1])
    {
        if(a[0][1]==1)return s+1;
        else if(a[0][1]==2)return -(s+1);
    }
    if(a[0][2]==a[1][2]&&a[0][2]==a[2][2])
    {
        if(a[0][2]==1)return s+1;
        else if(a[0][2]==2)return -(s+1);
    }
    if(a[0][0]==a[1][1]&&a[0][0]==a[2][2])
    {
        if(a[0][0]==1)return s+1;
        else if(a[0][0]==2)return -(s+1);
    }
    if(a[0][2]==a[1][1]&&a[1][1]==a[2][0])
    {
        if(a[0][2]==1)return s+1;
        else if(a[0][2]==2)return -(s+1);
    }
 
    return 0;
 
}
int minn(int dep,int al,int pe)
{
    if(value()!=0)return value();
    int ar=al,pi=pe;
    if(dep<=0)
    {
        return value();
    }
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(a[i][j]==0)
            {
                a[i][j]=2;
 
                int val=maxx(dep-1,ar,pi);
                a[i][j]=0;
                pi=min(pi,val);
                if(ar>=pi)return pi;
            }
        }
    }
    return pi;
}
int maxx(int dep,int al,int pe)
{
    if(value()!=0)return value();
    int ar=al,pi=pe;
    if(dep<=0)
    {
        return value();
 
    }
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(a[i][j]==0)
            {
                a[i][j]=1;
 
 
                int val=minn(dep-1,ar,pi);
                a[i][j]=0;
                ar=max(ar,val);
                if(ar>=pi)return ar;
            }
        }
    }
    return ar;
}
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int o=0;
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                scanf("%d",&a[i][j]);
                if(a[i][j]==0)o++;
            }
        }
        int u=maxx(o,-10,10);
        printf("%d\n",u);
    }
 
}
 

