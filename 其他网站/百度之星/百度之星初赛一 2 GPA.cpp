#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	
	int fenshu[11]={0,60,62,65,67,70,75,80,85,90,95};
	double gpa[11]={0.0,1.0,1.7,2.0,2.3,2.7,3.0,3.3,3.7,4.0,4.3};
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int zongfen;
		scanf("%d",&zongfen);
		double maxgpa=0;
		for(int h=0;h<11;h++)
		for(int i=0;i<11;i++)
		for(int j=0;j<11;j++)
		for(int k=0;k<11;k++)
		{
			int fen=fenshu[h]+fenshu[i]+fenshu[j]+fenshu[k];
			if(fen<=zongfen)
			{
				double tempgpa=gpa[h]+gpa[i]+gpa[j]+gpa[k];
				if(tempgpa>maxgpa)
					maxgpa=tempgpa;
			}
		}
		printf("%.1f\n",maxgpa);
	}
	return 0;
}
