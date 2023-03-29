#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
int n,q,a[1005],len,b; 
int main()
{
	cin>>n>>q;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	while(q--)
	{
		cin>>len>>b;
		//string s=to_string(b);
		//int len=s.length();
		int mod=1;
		for(int i=1;i<=len;i++)
			mod*=10;
		int flag=1;
		for(int i=0;i<n;i++)
		{
			if(a[i]%mod==b)//a[i]ĩβlenλ 
			{
				cout<<a[i]<<endl;
				flag=0;
				break;
			}
		}
		if(flag==1)
			cout<<"-1"<<endl;
	}
	return 0;
}
