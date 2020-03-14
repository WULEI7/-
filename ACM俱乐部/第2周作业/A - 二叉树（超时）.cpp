#include <cstdio>
#include <iostream>
using namespace std;
int m,n,ans;
void search(int x)
{
	if(x>n) return;
	else
	{
		ans++;
		search(2*x);
		search(2*x+1);
	}
}
int main()
{
	while(scanf("%d%d",&m,&n)==2)
	{
		if(m==0) break;
		ans=0;
		search(m);
		cout<<ans<<endl;
	}
	return 0;
}
