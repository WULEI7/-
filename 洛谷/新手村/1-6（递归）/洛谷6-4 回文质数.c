#include <stdio.h>
int ishuiwen(int n)
{
	int a,b=0;
	a=n;
	while(a!=0){
		b=b*10+a%10;
		a=a/10;}
	if(n==b) return 1;
	else return 0;
}
int main()
{
	int a,b,i,m,flag;
	scanf("%d %d",&a,&b);
	if(b>9989899) b=9989899;
	for(m=a;m<=b;m++)
	{
		if(ishuiwen(m)==0||m%2==0) continue;
		flag=1;
		for(i=3;i*i<=m;i++)
			if(m%i==0)
			{flag=0;break;}
		if(flag==1) printf("%d\n",m);
	}
	return 0;
}
