#include <iostream>
#include <cstdio>
#include <cstring> 
using namespace std;
int num=1,qp[10][10];//�������֣����� 

void devide(int lr,int lc,int tr,int tc,int size)//���Σ������ֱ�Ϊ�����Ͻ�λ�������к��С��Ѹ���λ�������к��С���ǰ���̴�С 
{
	if(size==1) return; 
	int s=size/2;//��ǰ���̴�С 
	int no=num++;//��ǰ�������� 
	
	if(tr<lr+s&&tc<lc+s)
		devide(lr,lc,tr,tc,s);
	else
	{
		qp[lr+s-1][lc+s-1]=no;
		devide(lr,lc,lr+s-1,lc+s-1,s);
	}//���Ͻ����� 
	
	if(tr<lr+s&&tc>=lc+s)
		devide(lr,lc+s,tr,tc,s);
	else
	{
		qp[lr+s-1][lc+s]=no;
		devide(lr,lc+s,lr+s-1,lc+s,s);
	}//���Ͻ����� 
	
	if(tr>=lr+s&&tc<lc+s)
		devide(lr+s,lc,tr,tc,s);
	else
	{
		qp[lr+s][lc+s-1]=no;
		devide(lr+s,lc,lr+s,lc+s-1,s);
	}//���½����� 
	
	if(tr>=lr+s&&tc>=lc+s)
		devide(lr+s,lc+s,tr,tc,s);
	else
	{
		qp[lr+s][lc+s]=no;
		devide(lr+s,lc+s,lr+s,lc+s,s);
	}//���½����� 
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int k,t,m,n;
	cin>>k>>m>>n;
	if(k==2) t=4;
	if(k==3) t=8;
	memset(qp,0,sizeof(0));
	qp[m-1][n-1]=-1;
	devide(0,0,m-1,n-1,t);
	for(int i=0;i<t;i++)
	{
		for(int j=0;j<t;j++)
			cout<<qp[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}
