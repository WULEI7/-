#include <stdio.h>
int main()
{
	int n,s,a,b,i,j,wz,temp,sum=0,tot=0,pg[5000][2],ng[5000];
	scanf("%d %d",&n,&s);
	scanf("%d %d",&a,&b);
	for(i=0;i<n;i++)
		scanf("%d %d",&pg[i][0],&pg[i][1]);
	for(i=0;i<n;i++)
		if(a+b>=pg[i][0])
			ng[sum++]=pg[i][1];//将高度可以够到的苹果需要的力气存入数组ng 
	for(i=0;i<sum-1;i++)
	{
		wz=i;
		for(j=i+1;j<sum;j++)
			if(ng[j]<ng[wz])
				wz=j;
		temp=ng[i];
		ng[i]=ng[wz];
		ng[wz]=temp;
	}//对数组ng进行选择排序 
	while(s>0)
		s-=ng[tot++];//用力量s摘数组ng中的苹果 
	if(s==0) printf("%d",tot);
	else printf("%d",tot-1);
	return 0;
}
