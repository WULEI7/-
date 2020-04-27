#include <iostream>
#include <cmath>
using namespace std;
long long Com(long long m,long long n)
{
	long long temp=1;
	for(long long i=m;i>m-n;i--)
		temp*=i;
	for(long long i=1;i<=n;i++)
		temp/=i;
	return temp;
}//×éºÏÊý 
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		double r,s,x,y,w,winp,losp,prob=0;
		cin>>r>>s>>x>>y>>w;
		winp=(s-r+1)/s;
		losp=(r-1)/s;
		for(int i=x;i<=y;i++)
			prob+=Com(y,i)*pow(winp,i)*pow(losp,y-i);
		if(prob>1/w)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}
	return 0;
}
