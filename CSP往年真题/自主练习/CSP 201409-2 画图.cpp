#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
	int pic[105][105]={0},n,x1,y1,x2,y2,ans=0;
	cin>>n;
	while(n--)
	{
		cin>>x1>>y1>>x2>>y2;
		for(int i=x1;i<x2;i++)
		for(int j=y1;j<y2;j++)
			pic[i][j]=1;
	}
	for(int i=0;i<=100;i++)
	for(int j=0;j<=100;j++)
		if(pic[i][j]==1)
			ans++;
	cout<<ans<<endl;
	return 0;
}
