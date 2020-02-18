#include <bits/stdc++.h>
using namespace std;
int main()
{
	int i,sum=0;
	char a[8];
	cin >> a; 
	for(i=0;i<8;i++)
		if(a[i]=='1') sum++;
	cout << sum;
	return 0;
}
