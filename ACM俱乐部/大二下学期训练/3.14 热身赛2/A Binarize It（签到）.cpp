#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t,n,a[17]={2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072};
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<17;i++)
			if(a[i]>=n)
			{
				printf("Input value: %d\n",n);
				printf("%d\n\n",a[i]);
				break;
			}
	}
	return 0;
}
