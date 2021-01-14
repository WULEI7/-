#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,x[1005],y[1005],r[1005],x1,x2,y1,y2,cnt=0;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>x[i];
	for(int i=0;i<n;i++)
		cin>>y[i];
	for(int i=0;i<n;i++)
		cin>>r[i];
	cin>>x1>>y1>>x2>>y2;
	for(int i=0;i<n;i++)
	{
		int flag=0;
		if((x[i]-x1)*(x[i]-x1)+(y[i]-y1)*(y[i]-y1)>r[i]*r[i]) flag++;
		if((x[i]-x2)*(x[i]-x2)+(y[i]-y2)*(y[i]-y2)>r[i]*r[i]) flag++;
		if(flag==1) cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}
