#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
	int n,maxx=0,minn=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		if(i%7==0||i%7==6) minn++;
		if(i%7==1||i%7==2) maxx++;
	}
	cout<<minn<<" "<<maxx<<endl;
	return 0;
}
