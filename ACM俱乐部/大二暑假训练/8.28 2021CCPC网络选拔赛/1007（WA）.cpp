#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
long long g(long long x)
{
	long long temp=0;
	while(x)
	{
		temp+=x%10;
		x/=10;
	}
	return temp;
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;
	long long k[8]={1,9,99,999,9999,99999,999999,9999999};
	cin>>t;
	while(t--)
	{
		long long a,b,c,d,n,m,f,y,ans;
		cin>>a>>b>>c>>d>>n;
		m=n;
		//cout<<g(n)<<endl;
		ans=min(a*n*n*g(n)+b*n*n+c*n*g(n)*g(n)+d*n*g(n),a+b+c+d);
		int pos=0;
		for(;pos<8;pos++)
			if(k[pos]>n) break;
		n=k[pos-1];
		ans=min(ans,a*n*n*g(n)+b*n*n+c*n*g(n)*g(n)+d*n*g(n));
		//cout<<ans<<endl;
		int temp=0;
		while(m>10)
		{
			m/=10;
			temp++;
		}
		f=m;
		//cout<<f<<" "<<temp<<endl;
		n=y=f-1;
		m=1;
		while(temp--)
		{
			n=n*10+9;
			m*=10;
			y*=10;
		}
		n=max(1LL,n);
		m=max(1LL,m);
		y=max(1LL,y);
		//cout<<n<<endl;
		ans=min(ans,a*n*n*g(n)+b*n*n+c*n*g(n)*g(n)+d*n*g(n));
		n=m;
		//cout<<n<<endl;
		ans=min(ans,a*n*n*g(n)+b*n*n+c*n*g(n)*g(n)+d*n*g(n));
		n=y;
		ans=min(ans,a*n*n*g(n)+b*n*n+c*n*g(n)*g(n)+d*n*g(n));
		cout<<ans<<endl;
	}
	return 0;
}
