#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,temp=0,last,ans=0;
	cin>>n;
	for(int i=1;;i++)
	{
		if(temp+i>n)//等号加不加一样 
		{last=i;break;}
		else temp+=i;
	}
	for(int i=1;i<last;i++)
		ans+=i*i;
	ans+=(n-temp)*last;
	cout<<ans;
	return 0;
}
