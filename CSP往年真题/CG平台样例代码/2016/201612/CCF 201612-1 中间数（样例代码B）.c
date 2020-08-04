#include<stdio.h>
int main()
{
	int n,a[1005],i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%d",&a[i]);
	for(i=0;i<n;i++){
		int x,y;
		x=0;y=0;
		for(j=0;j<n;j++){
			if(a[j]>a[i])x++;
			if(a[j]<a[i])y++;
		}
		if(x==y){
			printf("%d",a[i]);
			return 0;
		}	
	}
	printf("-1");
    return 0;
}



