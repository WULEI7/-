#include <bits/stdc++.h>
using namespace std;
int fun(int n)
{
	if(n==0||n==1) return 1;
	else if(n%2==0) return fun(n-1)+fun(n/2);
	else return fun(n-1);
}
int main()
{
	int n;
	cin >> n;
	cout << fun(n);
	return 0;
}
