#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int a,b,n,num[50];
	while(scanf("%d%d%d",&a,&b,&n)==3)
	{
		if(n==0) break;
		num[1]=num[2]=1;
		for(int i=3;i<50;i++)
			num[i]=(a*(num[i-1]%7)+b*(num[i-2]%7))%7;
		cout<<num[(n-1)%49+1]<<endl;
	}
	return 0;
}
