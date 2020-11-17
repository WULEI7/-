#include <iostream>
#include <cstdio>
#include <cstring> 
using namespace std;
int a[300005]={0};
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t,n;
	cin>>t;
	while(t--)
	{
		memset(a,0,sizeof(a));
		cin>>n;
		int d=0,l=0,r=0;
		char x;
		for(int i=0;i<n;i++)
		{
			cin>>x;
			if(x=='-') a[i]=1;
			if(x=='<') l++;
			if(x=='>') r++;
		}
		if(l>0&&r>0)
		{
			int ans=0,temp=0;
			for(int i=0;i<n;i++)
			{
				if(a[i]==1)
					temp++;
				else
				{
					if(temp>0)
						ans+=temp+1;
					temp=0;
				}
			}
			if(temp>0)
				ans+=temp+1;
			if(a[0]==1&&a[n-1]==1)
				ans--;
			cout<<ans<<endl;
		}
		else
			cout<<n<<endl;
	}
	return 0;
}
