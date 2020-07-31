#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int t;
	long long n,g,b,hq,ans;
	cin>>t;
	while(t--)
	{
		cin>>n>>g>>b;
		hq=(n-1)/2+1;//hq为需要好天气的最少日数 
		if(hq%g==0)
			ans=(g+b)*(hq/g)-b;
		else
			ans=(g+b)*(hq/g)+hq%g;
		cout<<max(ans,n)<<endl;//若好天气的已完成，总工作天数还没满，也需要完成总工作天数 
	}
	return 0;
}
