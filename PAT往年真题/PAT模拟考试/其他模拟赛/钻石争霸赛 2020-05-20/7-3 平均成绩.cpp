#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n,x,c,na=0,nb=0,sum=0,suma=0,sumb=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&x,&c);
		sum+=c;
		if(x==1)
		{
			na++;
			suma+=c;
		}
		else
		{
			nb++;
			sumb+=c;
		}
	}
	printf("%.1f ",(float)sum/n);
	if(na==0)
		printf("X ");
	else
		printf("%.1f ",(float)suma/na);
	if(nb==0)
		printf("X");
	else
		printf("%.1f",(float)sumb/nb);
	return 0;
}
