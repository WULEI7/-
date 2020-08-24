#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
	int n,k,a,ans=0,temp=0;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		if(temp+a>=k)
		{
			ans++;
			temp=0;
		}
		else
			temp+=a;
	}
	if(temp>0)
		ans++; 
	cout<<ans<<endl;
	return 0;
}
