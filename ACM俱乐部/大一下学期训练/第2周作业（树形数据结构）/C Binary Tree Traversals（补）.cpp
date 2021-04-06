#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector> 
using namespace std;
int a[1005],b[1005];
vector<int> ans;
void build(int l1,int r1,int l2,int r2)
{
	for(int i=l2;i<=r2;i++)
	{
		if(b[i]==a[l1])
		{
			build(l1+1,l1+i-l2,l2,i-1);
			build(l1+i-l2+1,r1,i+1,r2);
			ans.push_back(a[l1]);
			break;
		}
	}
}
int main()
{
	int len;
	while(cin>>len)
	{
		for(int i=0;i<len;i++)
			cin>>a[i];
		for(int i=0;i<len;i++)
			cin>>b[i];
		ans.clear();
		build(0,len-1,0,len-1);
		cout<<ans[0];
		int size=ans.size();
		for(int i=1;i<size;i++)
			cout<<" "<<ans[i];
		cout<<endl;
	}
	return 0;
}
