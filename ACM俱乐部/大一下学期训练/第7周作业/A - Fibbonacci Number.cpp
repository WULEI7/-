#include <iostream>
using namespace std;
int main()
{
	long long num[52];
	num[0]=0;
	num[1]=1;
	for(int i=2;i<=50;i++)
		num[i]=num[i-1]+num[i-2];
	int n;
	while(cin>>n)
	{
		if(n==-1) break;
		cout<<num[n]<<endl;
	}
	return 0;
}
