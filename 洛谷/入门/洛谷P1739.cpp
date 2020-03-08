#include <bits/stdc++.h>
using namespace std;
int main()
{
	char a[256];
	int temp=0;
	cin>>a;
	int k=strlen(a);
	for(int i=0;i<k;i++)
	{
		if(a[i]=='(') temp++;
		if(a[i]==')') temp--;
		if(temp<0)
		{cout<<"NO";return 0;}
	}
	if(temp==0) cout<<"YES";
	else cout<<"NO";
	return 0;
}
