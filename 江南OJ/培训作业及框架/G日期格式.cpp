#include <bits/stdc++.h>
using namespace std;
int main()
{
	char a[10];
	int i;
	for(i=0;i<10;i++)
		cin>>a[i];
	for(i=6;i<10;i++)
		cout<<a[i];
	cout<<"-";
	for(i=0;i<5;i++)
		cout<<a[i];
	return 0;
}
