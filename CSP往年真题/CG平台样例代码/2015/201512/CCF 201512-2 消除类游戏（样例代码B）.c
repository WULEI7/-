#include <stdio.h>
int main()
{
	int n,m,i,j,qipan[35][35],biaoji[35][35]={0};
	//qipan����������������ӵ���ɫ��������һ��biaoji���������������ÿ��λ���Ƿ�ᱻ����������Ԫ�س�ʼ��Ϊ0 
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			scanf("%d",&qipan[i][j]);//�����������ɫ��� 
	for(i=1;i<=n;i++)
		for(j=1;j<=m-2;j++)
			if(qipan[i][j]==qipan[i][j+1]&&qipan[i][j]==qipan[i][j+2])
				biaoji[i][j]=biaoji[i][j+1]=biaoji[i][j+2]=1;
	//�ж�ÿһ�У������ң��Ƿ�����������������ࣩ��ɫ��ͬ�����ӣ����У���biaoji�����ж�Ӧλ��Ԫ��ȫ�����Ϊ1 
	for(j=1;j<=m;j++)
		for(i=1;i<=n-2;i++)
			if(qipan[i][j]==qipan[i+1][j]&&qipan[i][j]==qipan[i+2][j])
				biaoji[i][j]=biaoji[i+1][j]=biaoji[i+2][j]=1;
	//�ж�ÿһ�У����ϵ��£��Ƿ�����������������ࣩ��ɫ��ͬ�����ӣ����У���biaoji�����ж�Ӧλ��Ԫ��ȫ�����Ϊ1 
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(biaoji[i][j]==1)
				qipan[i][j]=0;//����biaoji���飬����б��Ϊ1����qipan�����Ӧλ��Ԫ�ظ�Ϊ0 
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			printf("%d",qipan[i][j]);
			if(j<m) printf(" ");
		}
		printf("\n");
	}//������˳�����qipan���飬�ո�ͻ��е���������Ͻ� 
	return 0;
}
