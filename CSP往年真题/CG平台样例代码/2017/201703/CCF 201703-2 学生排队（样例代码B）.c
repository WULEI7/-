#include<stdio.h>
int main()
{
	int a[1005],n,m,x,y,flag,i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)a[i]=i;
	while(m--){
		scanf("%d%d",&x,&y);
		for(i=1;i<=n;i++){
			if(a[i]==x)flag=i;
		}
		if(y>0&&y<=n-flag){
			int t=a[flag];
			for(j=flag;j<flag+y;j++)a[j]=a[j+1];
			a[flag+y]=t;
		}
		else if(y<0&&-1*y<flag){
			y*=-1;
			int t=a[flag];
			for(j=flag;j>flag-y;j--)a[j]=a[j-1];
			a[flag-y]=t;
		}
	}
	for(i=1;i<=n;i++){
		if(i!=n)printf("%d ",a[i]);
		else printf("%d",a[i]);
	}
    return 0;
}




