#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t,len;
	string a,b;
	char x[100005],y[100005];
	cin>>t;
	while(t--)
	{
		cin>>len>>a>>b;
		int temp=0;
		for(int i=0;i<len;i++)
		{
			if(a[i]!=b[i])
			{
				x[temp]=a[i];
				y[temp]=b[i];
				temp++;
			}
		}
		int flag=0;
		if(temp==0) flag=1;
		for(int i=0;i<temp;i++)
		{
			if(x[i]!=y[(i+1)%temp]) break;
			if(i==temp-1) flag=1;
		}
		for(int i=0;i<temp;i++)
		{
			if(x[(i+1)%temp]!=y[i]) break;
			if(i==temp-1) flag=1;
		}
		if(flag==1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
