#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,a,b,v[1005]={0},cnt=0;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		cin>>a>>b;
		v[a]++;
		v[b]++;
	}
	for(int i=1;i<=n;i++)
		if(v[i]%2)
			cnt++;//Ææµã¸öÊý 
	if(cnt==0||cnt==2)
		cout<<"1"<<endl;
	else
		cout<<cnt/2<<endl;
	return 0;
}
