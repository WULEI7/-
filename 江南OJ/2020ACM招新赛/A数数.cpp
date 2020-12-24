#include <bits/stdc++.h>
using namespace std;
int main()
{
	int num[10]={1,0,0,0,1,0,1,0,2,1},ans=0;
	char a[20];
	cin>>a;
	int k=strlen(a);
	for(int i=0;i<k;i++)
		ans+=num[a[i]-'0'];
	cout<<ans;
	return 0;
}
