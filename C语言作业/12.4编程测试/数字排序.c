#include <stdio.h>
int main()
{
	int n,i,j,cd,temp,a[1000],b[1001]={0},c[1001][2];
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);//����a�������� 
	for(i=0;i<n;i++)
		b[a[i]]++;
	cd=0;
	for(i=0;i<=1000;i++)
		if(b[i]>0) 
		{
			c[cd][0]=i;
			c[cd][1]=b[i];
			cd++;
		}//����bͳ�Ƹ����ֳ��ֵĴ��� 
	for(i=0;i<cd-1;i++)
		for(j=i+1;j<cd;j++)
	{
		if(c[i][1]<c[j][1])
		{
			temp=c[i][0];
			c[i][0]=c[j][0];
			c[j][0]=temp;
			temp=c[i][1];
			c[i][1]=c[j][1];
			c[j][1]=temp;
		}
	}//����c���ո����ֳ��ִ������ٴ����������� 
	for(i=0;i<cd-1;i++)
		for(j=i+1;j<cd;j++)
	{
		if(c[i][1]==c[j][1]&&c[i][0]>c[j][0])
		{
			temp=c[i][0];
			c[i][0]=c[j][0];
			c[j][0]=temp;
			temp=c[i][1];
			c[i][1]=c[j][1];
			c[j][1]=temp;
		}
	}//���ֳ��ִ�����ͬʱ����������С�����ϴ������ 
	for(i=0;i<cd;i++)
		printf("%d %d\n",c[i][0],c[i][1]);
	return 0;
}
