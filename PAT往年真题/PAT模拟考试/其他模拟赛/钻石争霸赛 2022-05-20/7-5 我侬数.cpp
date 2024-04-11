#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string x,y;
	int pos=0,len=0,tot[10]={0},cnt[10]={0};
	cin>>x>>y;
	len=x.length();
	pos=0;
	while(x[pos]=='0')
		pos++;
	for(;pos<len;pos++)
		tot[x[pos]-'0']++;
	len=y.length();
	pos=0;
	while(y[pos]=='0')
		pos++;
	for(;pos<len;pos++)
		tot[y[pos]-'0']++;
	while(cin>>x>>y)
	{
		if(x=="0"&&y=="0") break;
		for(int i=0;i<10;i++)
			cnt[i]=0;
		len=x.length();
		pos=0;
		while(x[pos]=='0')
			pos++;
		for(;pos<len;pos++)
			cnt[x[pos]-'0']++;
		len=y.length();
		pos=0;
		while(y[pos]=='0')
			pos++;
		for(;pos<len;pos++)
			cnt[y[pos]-'0']++;
		int flag=1;
		for(int i=0;i<10;i++)
			if(tot[i]!=cnt[i])
			{flag=0;break;}
		if(flag)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}
