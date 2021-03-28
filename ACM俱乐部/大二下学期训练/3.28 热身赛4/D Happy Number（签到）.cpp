#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
map<int,int> mp;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,flag=0;
	cin>>n;
	int t=n; 
	while(1)
	{
		int temp=0;
		while(t)
		{
			int x=t%10;
			temp+=x*x;
			t/=10;
		}
		if(temp==1)
		{
			flag=1;
			break;
		}
		if(mp[temp]==1)
		{
			flag=0;
			break;
		}
		mp[temp]=1;
		t=temp;
	}
	if(flag==1)
		cout<<"HAPPY"<<endl;
	else
		cout<<"UNHAPPY"<<endl;
	return 0;
}
