#include <bits/stdc++.h>
using namespace std;
char a[100001],b[100001],str[200001];
int main()
{
	int i,i1=0,i2=0,k1,k2;
	cin>>a;
	cin>>b;
	k1=strlen(a);
	k2=strlen(b);
	if(k1>=k2)
	for(i=0;i1<=k1;i++)
	{
		if(i%2==0||i2==k2) str[i]=a[i1++];
		else str[i]=b[i2++];
	}
	else
	for(i=0;i2<=k2;i++)
	{
		if(i%2==0&&i1<k1) str[i]=a[i1++];
		else str[i]=b[i2++];
	}
	cout<<str;
	return 0;
}
