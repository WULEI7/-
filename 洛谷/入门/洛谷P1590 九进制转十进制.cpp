#include <bits/stdc++.h>
using namespace std;
int main()
{
	int i,j,n,weishu,ans;
	char a[11];
	scanf("%d",&n);
	for(j=0;j<n;j++)//��forѭ������n��Pascal�� 
	{
		scanf("%s",a);
		weishu=strlen(a);//��¼�������ֵ�λ�� 
		ans=0;//�����ĸ������� 
		for(i=0;i<weishu;i++) 
		{
			if(a[i]=='8'||a[i]=='9') a[i]-=1;//���λ����8��9����7��8 
			ans+=(a[i]-'0')*pow(9,weishu-i-1);//Ȼ���൱�ھŽ���ת��ʮ���ƣ�����Ž��Ƶ�123����ʮ���Ƶ� 1*81+2*9+3*1=102 
		}
		printf("%d\n",ans);//������ĸ��� 
	}
	return 0;
}
