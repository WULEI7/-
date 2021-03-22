#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t,b[27];
	char a[10005];
	cin>>t;
	cin>>a;
	memset(b,0,sizeof(b));
	int len=strlen(a);
	for(int i=0;i<len;i++)
		b[a[i]-'a']++;
	int pd=0;
	for(int i=0;i<26;i++)
		if(b[i]%2) pd++;
	if(pd>1)
	{
		cout<<"Impossible"<<endl;
		return 0;
	}//如果有超过一个字母出现奇数次，则不可能成为回文串，直接输出Impossible 
	int l=0,r=len-1,ans=0;
	while(r-l>1)//结束条件 
	{
		if(a[l]==a[r])
		{l++;r--;continue;}
		int len1,len2;
		for(int j=l+1;j<=r;j++)
			if(a[j]==a[r])
			{len1=j-l;break;}
		for(int j=r-1;j>=l;j--)
			if(a[j]==a[l])
			{len2=r-j;break;}
		if(len1<=len2)
		{
			ans+=len1;
			char temp=a[l+len1];
			for(int i=l+len1;i>l;i--)
				a[i]=a[i-1];
			a[l]=temp;
		}
		else
		{
			ans+=len2;
			char temp=a[r-len2];
			for(int i=r-len2;i<r;i++)
				a[i]=a[i+1];
			a[r]=temp;
		}
		l++;r--;
	}//从两头往中间，字符串长度为奇数或偶数的情况都能处理 
	cout<<ans<<endl;
	return 0;
}
