#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,baoshu=1,cnt=0,s[105];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		s[i]=i;
	for(int i=1;i<=n;i++)
	{
		if(s[i]!=0)
		{
			if(baoshu%m==0)
			{
				s[i]=0;
				printf("%d",i);
				if(cnt<n)
					printf(" ");
				cnt++;
			}
			baoshu++;
		}
		if(cnt==n) break; 
		if(i==n) i=0;
	}
	printf("\n");
	return 0;
}
