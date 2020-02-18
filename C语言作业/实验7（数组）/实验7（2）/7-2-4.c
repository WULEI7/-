#include <stdio.h>
#define N 4
#define M 4
main()
{
   	int i,j,k,flag1,flag2,a[N][M],max,maxj;
   	for(i=0;i<N;i++)
    	for(j=0;j<M;j++)
			scanf("%d",&a[i][j]); 
   	flag2=0;
   	for(i=0;i<N;i++)
   	{
		max=a[i][0];
		for(j=0;j<M;j++)
    		if(a[i][j]>max)
        	{
        		max=a[i][j];
           		maxj=j;
        	}
     	for(k=0,flag1=1;k<N&&flag1;k++)
        	if(max>a[k][maxj]) flag1=0;
  		if(flag1)
  		{
     		printf("\nThe saddle point is :a[%d][%d]=%d\n",i,maxj,max);
     		flag2=1;
  		}
   	}
	if(!flag2)
  	printf("\nThere is no saddle point in the Matrix\n");
  	return 0; 
}
