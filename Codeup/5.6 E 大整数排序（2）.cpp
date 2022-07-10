#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;
int n;
string a[105];
 
int cmp(string aa,string bb)
{
    if(aa.size()<bb.size())
    {
        return 1;
    }
    else if(aa.size()==bb.size())
    {
        return aa<bb;
    }
    else
    {
        return 0;
    }
}
 
int main()
{
    while(scanf("%d",&n)==1)
    {
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        sort(a,a+n,cmp);
        for(int i=0;i<n;i++)
        {
            cout<<a[i]<<endl;
        }
 
 
 
    }
    return 0;
}