#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		int n,a[102],b[102],isstack=0,isqueue=0;
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=0;i<n;i++)
			cin>>b[i];
		int flag1=1;
		for(int i=0;i<n;i++)
			if(a[i]!=b[i])
			{flag1=0;break;}
		if(flag1==1) isqueue=1;
		reverse(b,b+n);
		int flag2=1;
		for(int i=0;i<n;i++)
			if(a[i]!=b[i])
			{flag2=0;break;}
		if(flag2==1) isstack=1;
		
		if(isstack==0&&isqueue==0) cout<<"neither"<<endl;
		if(isstack==1&&isqueue==0) cout<<"stack"<<endl;
		if(isstack==0&&isqueue==1) cout<<"queue"<<endl;
		if(isstack==1&&isqueue==1) cout<<"both"<<endl;
	}
	return 0;
}
