#include <cstdio>
#include <iostream>
using namespace std;
int t[1000005]={0};
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,a,b,cnt=0;
	cin>>n;
	for(int k=0;k<2;k++)
	{
		for(int i=0;i<n;i++)
		{
			cin>>a>>b;
			for(int j=a;j<b;j++)
				t[j]++;
		}
	}
	for(int i=1;i<1000000;i++)
		if(t[i]==2)
			cnt++;
	cout<<cnt<<endl;
	return 0;
}
