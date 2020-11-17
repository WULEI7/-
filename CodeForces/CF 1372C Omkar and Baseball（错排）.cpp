#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int a,flag=1,cnt=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a;
			if(a!=i&&flag==1)
			{
				cnt++;
				flag=0;
			}
			if(a==i)
				flag=1;
		}
		if(cnt==0)
			cout<<"0"<<endl;
		else if(cnt==1)
			cout<<"1"<<endl;
		else
			cout<<"2"<<endl;
	}
	return 0;
}
