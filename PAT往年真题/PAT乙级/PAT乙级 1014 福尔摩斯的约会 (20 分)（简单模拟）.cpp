#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	int len1=min(a.length(),b.length());
	int len2=min(c.length(),d.length());
	int t=0,day,hour,minute;
	string D[7]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
	for(int i=0;i<len1;i++)
	{
		if(t==0&&a[i]>='A'&&a[i]<='G'&&a[i]==b[i])
		{
			day=a[i]-'A';
			t=1;
			continue;
		}
		if(t==1&&a[i]>='0'&&a[i]<='9'&&a[i]==b[i])
		{
			hour=a[i]-'0';
			break;
		}
		if(t==1&&a[i]>='A'&&a[i]<='N'&&a[i]==b[i])
		{
			hour=a[i]-'A'+10;
			break;
		}
	}
	for(int i=0;i<len2;i++)
	{
		if(c[i]>='A'&&c[i]<='z'&&c[i]==d[i])
		{
			minute=i;
			break;
		}
	}
	cout<<D[day]<<" ";
	if(hour<10)
		cout<<"0";
	cout<<hour<<":";
	if(minute<10)
		cout<<"0";
	cout<<minute<<endl;
	return 0;
}
