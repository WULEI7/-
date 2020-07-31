#include <iostream>
#include <cstdio>
using namespace std;
int m,k,num[1000005];
int gcd(int a,int b)
{
  if(b==0)
        return a;
  else
    return gcd(b,a%b);
}
int main()
{
	while(~scanf("%d%d",&m,&k))
	{
		int j=0,cnt=0;
		for(int i=1;i<=m;i++)
			if(gcd(i,m)==1)
			{
				num[j++]=i;
				cnt++;
			}
		int ans=m*((k-1)/cnt)+num[(k-1)%cnt];
		printf("%d\n",ans);
	}
	return 0;
}
