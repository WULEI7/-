#include <bits/stdc++.h>
using namespace std;
int car[10001][4];
int main()
{
	int n,x,y,i,j;
	cin>>n;
	int max=n,m=1,flag=1;
	while(n--)
	{
		cin>>car[m][0]>>car[m][1]>>car[m][2]>>car[m][3];
		m++;
	}
	cin>>x>>y;
	for(m=max;m>0;m--)
		if(x>=car[m][0]&&x<=car[m][0]+car[m][2]&&y>=car[m][1]&&y<=car[m][1]+car[m][3])
		{cout<<m;flag=0;break;}
	if(flag) cout<<"-1";
	return 0;
}
