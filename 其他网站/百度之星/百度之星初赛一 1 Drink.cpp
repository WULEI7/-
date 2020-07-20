#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m,ans=99999999;
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)
		{
			int x,y,temp;
			scanf("%d%d",&x,&y);
			if(m%x)
				temp=y*(m/x+1);
			else
				temp=y*(m/x);
			if(temp<ans)
				ans=temp;
		}
		printf("%d\n",ans);
	}
	return 0;
}
