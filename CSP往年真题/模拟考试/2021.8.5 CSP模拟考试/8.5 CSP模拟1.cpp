#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,flag=0;
	cin>>n;
	for(int i=1;i<=n/2;i++)
	{
		int sum=0;
		for(int j=i;j<n;j++)
		{
			sum+=j;
			if(sum==n)
			{
				flag=1;
				for(int k=i;k<=j;k++)
					cout<<k<<" ";
				cout<<endl;
			}
			if(sum>n)
				break;
		}
	}
	if(flag==0)
		cout<<"NONE"<<endl;
	return 0;
}
