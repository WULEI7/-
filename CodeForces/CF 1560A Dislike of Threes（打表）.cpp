#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t,n,a[1005];
	int temp=1,pos=1;
	while(1)
	{
		if(temp%10!=3&&temp%3!=0)
			a[pos++]=temp;
		temp++;
		if(pos>1000) break;
	}//´ò±í 
	cin>>t;
	while(t--)
	{
		cin>>n;
		cout<<a[n]<<endl;
	}
	return 0;
}
