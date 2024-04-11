#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t,a,b;
	cin>>t>>a>>b;
	if(a>=t&&b>=t)
		printf("*^_^*");
	//else if(a>=t&&b<t)
	else if(a>=t)
		printf("T_T");
	//else if(a<t&&b>=t)
	else if(b>=t)
		printf("-_-#");
	//else if(a<t&&b<t)
	else
		printf("-_-");
	return 0;
}
