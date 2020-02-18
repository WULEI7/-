#include <stdio.h>
int main()
{
	int n,i,j,k,l,s=0,flag=0,a[10][10]={0};
	scanf("%d",&n);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	for(k=1;k<n-1;k++)
		for(l=1;l<n-1;l++)
		{
			if(a[k][l]==0) flag++; 
			for(i=0;i<k;i++)
				if(a[i][l]==1) {flag++;break;}
			for(i=n-1;i>k;i--)
				if(a[i][l]==1) {flag++;break;}
			for(j=0;j<l;j++)
				if(a[k][j]==1) {flag++;break;}
			for(j=n-1;j>l;j--)
				if(a[k][j]==1) {flag++;break;}
			if(flag==5) s++;
			flag=0;
		}
	printf("%d",s);
	return 0;	
}
