#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t,n,a[100005],pos[100005];
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			pos[a[i]]=i;
		}
		int len=n;
		vector<int> vec;
		while(len>0)
		{
			for(int i=n;i>=0;i--)
				if(pos[i]<len)
				{
					for(int j=pos[i];j<len;j++)
						vec.push_back(a[j]);
					len=pos[i];
				}
		}
		for(int i=0;i<n;i++)
			printf("%d ",vec[i]);
		printf("\n");
	}
	return 0;
}
