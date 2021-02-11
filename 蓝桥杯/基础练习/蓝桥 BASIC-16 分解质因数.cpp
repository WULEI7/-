#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int main()
{
	int a,b;
	cin>>a>>b;
	for(int i=a;i<=b;i++)
	{
		int n=i;
		vector<int> v;
		for(int j=2;;j++)
		{
			while(n%j==0)
			{
				v.push_back(j);
				n/=j;
			}
			if(n==1) break;
		}
		printf("%d=%d",i,v[0]);
		int size=v.size();
		for(int j=1;j<size;j++)
			printf("*%d",v[j]);
		printf("\n");
	}
	return 0;
}
