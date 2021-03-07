#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,flag=1;
	char a[25][25];
	cin>>n;
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
		cin>>a[i][j];
	for(int i=0;i<n;i++)
	{
		int wcnt=0,bcnt=0,lx=1;
		if(a[i][0]=='W') wcnt++;
		if(a[i][0]=='B') bcnt++;
		for(int j=1;j<n;j++)
		{
			if(a[i][j]==a[i][j-1])
				lx++;
			else
				lx=1;
			if(lx>=3)
			{
				flag=0;
				goto label;
			}
			if(a[i][j]=='W') wcnt++;
			if(a[i][j]=='B') bcnt++;
		}
		if(wcnt!=bcnt)
		{
			flag=0;
			goto label;
		}
	}
	for(int j=0;j<n;j++)
	{
		int wcnt=0,bcnt=0,lx=1;
		if(a[0][j]=='W') wcnt++;
		if(a[0][j]=='B') bcnt++;
		for(int i=1;i<n;i++)
		{
			if(a[i][j]==a[i-1][j])
				lx++;
			else
				lx=1;
			if(lx>=3)
			{
				flag=0;
				goto label;
			}
			if(a[i][j]=='W') wcnt++;
			if(a[i][j]=='B') bcnt++;
		}
		if(wcnt!=bcnt)
		{
			flag=0;
			goto label;
		}
	}
	label:
	if(flag==1)
		cout<<"1"<<endl;
	else
		cout<<"0"<<endl;
	return 0;
}
