#include <iostream>
#include <cstdio>
#include <sstream>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int a[100],t,n=0;
	stringstream scin;
	string s;
	getline(cin,s);
	scin<<s;
	while(scin>>t)
		a[++n]=t;
	int ans=0,temp=0,left=0,right=0,tl=0,tr=0;
	for(int i=1;i<=n;i++)
	{
		if(temp>0)
		{
			temp+=a[i];
			tr=i;
		}
		else
		{
			temp=a[i];
			tl=tr=i;
		}
		if(temp>ans)
		{
			ans=temp;
			left=tl;
			right=tr;
		}
	}
	cout<<ans<<endl<<left<<endl<<right<<endl;
	return 0; 
}
