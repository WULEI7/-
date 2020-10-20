#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t,n,m,a[100005];
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=0;i<n;i++)
			cin>>a[i];
		int pos,mpos,maxn=0,temp=0,flag1=0,f=1;
		for(int i=0;i<n;i++)
		{
			if(temp+a[i]<=m)
				temp+=a[i];
			else
			{
				pos=i-1;
				f=0;
				break;
			}
			if(i==n-1&&f)
				flag1=1;
			if(a[i]>maxn)
			{
				maxn=a[i];
				mpos=i;
			}
		}
		if(flag1==1)
		{
			cout<<"0"<<endl;
			continue;
		}
		temp-=maxn;
		if(temp+a[pos+1]<=m)
			cout<<mpos+1<<endl;
		else
			cout<<"0"<<endl;
	}
	return 0;
}
