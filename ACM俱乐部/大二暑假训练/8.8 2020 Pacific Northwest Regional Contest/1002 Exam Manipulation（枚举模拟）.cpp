#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,k,ans=0;
	string t,s[1005];
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
		for(int j=0;j<k;j++)
		{
			if(s[i][j]=='T')
				s[i][j]='1';
			else
				s[i][j]='0';
		}
	}
	for(int z=0;z<(1<<k);z++)
	{
		int x=z,temp=999999;
		t.clear();
		while(x!=0)
		{
			if(x%2==1)
				t+='1';
			else
				t+='0';
			x/=2;
		}
		int len=t.length();
		for(int i=0;i<k-len;i++)
			t+='0';
		reverse(t.begin(),t.end());
		//cout<<t<<endl;
		for(int i=0;i<n;i++)
		{
			int cnt=0;
			for(int j=0;j<k;j++)
				if(s[i][j]==t[j])
					cnt++;
			if(cnt<temp)
				temp=cnt;
		}
		if(temp>ans)
			ans=temp;
	}
	cout<<ans<<endl;
	return 0;
}
