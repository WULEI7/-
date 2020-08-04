#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int m,n;
	while(cin>>m>>n)
	{
		if(m==0) break;
		int ans=0,row=1,t=m;
		while(t<n)
		{
			t=t*2+1;
			row++;
		}
		int temp=1;
		for(int i=0;i<row;i++)
		{
			ans+=temp;
			temp*=2;
		}
		temp/=2;//注意！这里必须先除以2，否则下面会超出int范围，保险起见开long long 
		ans-=t-max(m*temp-1,n);
		cout<<ans<<endl;
	}
	return 0;
}
