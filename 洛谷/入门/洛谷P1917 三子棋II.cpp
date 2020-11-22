#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	char a[3][3];
	int cnt=0;
	for(int i=0;i<3;i++)
	for(int j=0;j<3;j++)
	{
		cin>>a[i][j];
		if(a[i][j]!='-')
			cnt++;
	}
	if(a[0][1]=='X'||a[1][0]=='X'||a[1][2]=='X'||a[2][1]=='X')
		cout<<"xiaoa will win."<<endl;
	else
		cout<<"Dont know."<<endl;
	cout<<cnt<<endl;
	return 0; 
}
