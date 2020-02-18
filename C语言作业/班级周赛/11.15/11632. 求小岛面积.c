#include <stdio.h>
int main()
{
	int sea[9][9];
	int n,i,j,k,found,area;

	scanf("%d",&n);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&sea[i][j]);

	area=0;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(sea[i][j]==0)
			{
				found=0;
				for(k=j-1;k>=0;k--)
					if(sea[i][k]==1)
					{
						found++;
						break;
					}
				if(!found)
					continue;
				for(k=j+1;k<n;k++)
					if(sea[i][k]==1)
					{
						found++;
						break;
					}
				if(found!=2)
					continue;
				for(k=i-1;k>=0;k--)
					if(sea[k][j]==1)
					{
						found++;
						break;
					}
				if(found!=3)
					continue;
				for(k=i+1;k<n;k++)
					if(sea[k][j]==1)
					{
						found++;
						break;
					}
				if(found==4)
					area++;
			}
	printf("%d\n",area);
}
