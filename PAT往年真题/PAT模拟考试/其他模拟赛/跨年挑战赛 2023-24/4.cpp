#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int a[10],b[10];
	for(int i=1;i<=9;i++)
		cin>>a[i];
	for(int i=1;i<=8;i++)
	{
		if(i%2)
		{
			a[i+1]+=a[i]/2;
			b[i]=a[i]%2;
		}
		else
		{
			a[i+1]+=a[i]/3;
			b[i]=a[i]%3;
		}
	}
	b[9]=a[9];
	for(int i=1;i<=8;i++)
		cout<<b[i]<<" ";
	cout<<b[9]<<endl;
	return 0;
}
