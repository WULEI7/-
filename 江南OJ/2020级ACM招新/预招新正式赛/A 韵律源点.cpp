#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	long long n,a,b,c,ans1,ans2,ans3;
	cin>>n;
	cin>>a>>b>>c;
	ans1=n%100==0?a*(n/100):a*(n/100+1);
	ans2=n%510==0?b*(n/510):b*(n/510+1);
	ans3=n%1020==0?c*(n/1020):c*(n/1020+1);
	if(ans2<ans1) ans1=ans2;
	if(ans3<ans1) ans1=ans3;
	cout<<ans1<<endl;
	return 0;
}
