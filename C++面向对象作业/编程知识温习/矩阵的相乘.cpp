#include <bits/stdc++.h>
using namespace std;
int main()
{
	int i,j,k,a[3][3],b[3][3],c[3][3]={0};
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			cin>>a[i][j]; 
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			cin>>b[i][j];
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			for(k=0;k<3;k++)
				c[i][j]+=a[i][k]*b[k][j];
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
			cout<<c[i][j]<<" ";
		cout<<"\n";
	}
	return 0;
}
