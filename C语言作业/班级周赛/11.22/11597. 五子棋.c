#include <stdio.h>
int main()
{
	int chess[19][19],i,j,m,n,found,max=0;

	for(i=0;i<19;i++)
		for(j=0;j<19;j++)
			scanf("%d",&chess[i][j]);

	for(i=0;i<19;i++)
		for(j=0;j<19;j++)
		{
			if(chess[i][j]!=0)
			{
				found=1;
				for(m=j+1;m<19;m++)
					if(chess[i][m]!=chess[i][j])
						break;
					else
						found++;
				if(found==5)
				{
					printf("%d:%d,%d\n",chess[i][j],i+1,j+1);
					return 0;
				}
				if(found>max)
					max=found;

				found=1;
				for(m=i+1,n=j+1;m<19&&n<19;m++,n++)
					if(chess[m][n]!=chess[i][j])
						break;
					else
						found++;
				if(found==5)
				{
					printf("%d:%d,%d\n",chess[i][j],i+1,j+1);
					return 0;
				}
				if(found>max)
					max=found;

				found=1;
				for(m=i+1;m<19;m++)
					if(chess[m][j]!=chess[i][j])
						break;
					else
						found++;
				if(found==5)
				{
					printf("%d:%d,%d\n",chess[i][j],i+1,j+1);
					return 0;
				}
				if(found>max)
					max=found;

				found=1;
				for(m=i+1,n=j-1;m<19&&n<19;m++,n--)
					if(chess[m][n]!=chess[i][j])
						break;
					else
						found++;
				if(found==5)
				{
					printf("%d:%d,%d\n",chess[i][j],i+1,j+1);
					return 0;
				}
				if(found>max)
					max=found;
			}
		}

		printf("%d\n",max);
		return 0;
}
