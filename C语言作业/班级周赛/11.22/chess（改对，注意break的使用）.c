#include <stdio.h>
int main()
{
	int a[19][19],i,j,k,se=0,lian=0,flag=0,label=0;
	for(i=0;i<19;i++)
		for(j=0;j<19;j++)
			scanf("%d",&a[i][j]);
	for(i=0;i<19;i++)
	{
		for(j=0;j<19;j++)
		{
			flag=0;
			se=a[i][j];
			if(se==1||se==2) flag=1;
			else continue;//��continue������������������ֱ�ӽ�����һ��ѭ�� 
				for(k=1;k<=4;k++){
					if(a[i+k][j]==se) flag++;
					else break;}
				if(flag==5) {label=1;break;}//ע���Ⱥ�˳����label=1��break 
				else if(flag>lian) lian=flag;
				flag=1;
				for(k=1;k<=4;k++){
					if(a[i][j+k]==se) flag++;
					else break;}
				if(flag==5) {label=1;break;}
				else if(flag>lian) lian=flag;
				flag=1;
				for(k=1;k<=4;k++){
					if(a[i+k][j+k]==se) flag++;
					else break;}
				if(flag==5) {label=1;break;}
				else if(flag>lian) lian=flag;//�ֱ��ж����򡢺���б���Ƿ�������ӣ�û�����¼��������� 
		}
		if(label==1) break;//˫��ѭ������������ 
	}
	if(flag==5) printf("%d:%d,%d",se,i+1,j+1);
	else printf("%d",lian);
	return 0;
}
