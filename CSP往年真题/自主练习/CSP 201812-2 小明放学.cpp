#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	long long r,y,g,n,k,t,ans=0,time,T;//����T����-��-��,timeΪ��ǰ�����̵ƿ�ʼ��ʱ�� 
	cin>>r>>y>>g>>n;
	T=r+y+g;
	while(n--)
	{
		cin>>k>>t;
		if(k==0)
			ans+=t;
		else if(k==1)
		{
			time=(T-t+ans)%T;
			if(time>=g)
				ans+=T-time;
		}
		else if(k==2)
		{
			time=(T-r-t+ans)%T;
			if(time>=g)
				ans+=T-time;
		}
		else if(k==3)
		{
			time=(T-r-y-t+ans)%T;
			if(time>=g)
				ans+=T-time;
		}
	}
	cout<<ans<<endl;
	return 0;
}
