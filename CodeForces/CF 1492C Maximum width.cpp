#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int len1,len2,pos,ans=0,left[200005],right[200005];
	string a,b;
	cin>>len1>>len2;
	cin>>a>>b;
	pos=0;
	for(int i=0;i<len1;i++)
		if(a[i]==b[pos])
			left[pos++]=i;
	pos=len2-1;
	for(int i=len1;i>=0;i--)
		if(a[i]==b[pos])
			right[pos--]=i;
	for(int i=0;i<len2-1;i++)
	{
		int t=right[i+1]-left[i];
		if(t>ans) ans=t;
	}
	cout<<ans<<endl;
	return 0;
}
