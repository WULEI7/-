#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;
	long long n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		long long siz=1,cnt=0;
		while(1)
		{
			long long tot=(1+siz)*siz/2;
			if(n<tot) break;
			cnt++;
			n-=tot;
			siz=2*siz+1;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
