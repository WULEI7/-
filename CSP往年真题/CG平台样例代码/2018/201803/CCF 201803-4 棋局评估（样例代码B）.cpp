#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <queue>
#include<set>
#include <string>
#include <ctime>
#include<string.h>
#include <iostream>
#include <cstring>
using namespace std;
int n,a[5][5],x;
bool judge(int k)//�ж�k�Ƿ�Ӯ�ˣ�k=1����alice��k=2����bob�� 
{
	for(int i=1;i<=3;i++)
	{
	  if((a[i][1]==a[i][2])&&(a[i][2]==a[i][3])&&(a[i][3]==k))return true;
	  if((a[1][i]==a[2][i])&&(a[2][i]==a[3][i])&&(a[3][i]==k))return true;
  	}
  	if((a[1][1]==k)&&(a[2][2]==k)&&(a[3][3]==k))return true;
  	if((a[1][3]==k)&&(a[2][2]==k)&&(a[3][1]==k))return true;
	return false;
}
int dfs(int k)
{
	int t=0;
	for(int i=1;i<=3;i++)
	for(int j=1;j<=3;j++)if(a[i][j]==0)t++;	//����������пո��� 
	if((k==1)&&judge(2))return -t-1;  //��ΪbobӮ�ˣ�Ҫ����һ�����ţ� 
	if((k==2)&&judge(1))return t+1;  	
	if(t==0)return 0;
	int mn=10000000,mx=-1000000;
	for(int i=1;i<=3;i++)
	for(int j=1;j<=3;j++)
	if(a[i][j]==0)//��ÿһ���ո����ģ�⣻ 
	{
	  	a[i][j]=k;
	  	if(k==1)mx=max(mx,dfs(2));//�������Ϊ��Ҫ��������������Ե���䣬����alice��ѡ����һ�����ŵĽ⣻ 
	  	if(k==2)mn=min(mn,dfs(1));//ͬ�� 
	  	a[i][j]=0;//����ǰ���״̬�� 
	}
	if(k==1)return mx;
	if(k==2)return mn;	
}
int main()
{
	cin>>n;
	while(n--)
	{
		for(int i=1;i<=3;i++)
		for(int j=1;j<=3;j++)cin>>a[i][j];
		x=dfs(1);
		cout<<x<<endl;  
	}
	return 0;
} 






