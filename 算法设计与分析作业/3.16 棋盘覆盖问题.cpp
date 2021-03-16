#include <iostream>
#include <cstdio>
#include <cstring> 
using namespace std;
int num=1,qp[10][10];//骨牌数字，棋盘 

void devide(int lr,int lc,int tr,int tc,int size)//分治，参数分别为：左上角位置所在行和列、已覆盖位置所在行和列、当前棋盘大小 
{
	if(size==1) return; 
	int s=size/2;//当前棋盘大小 
	int no=num++;//当前骨牌数字 
	
	if(tr<lr+s&&tc<lc+s)
		devide(lr,lc,tr,tc,s);
	else
	{
		qp[lr+s-1][lc+s-1]=no;
		devide(lr,lc,lr+s-1,lc+s-1,s);
	}//左上角棋盘 
	
	if(tr<lr+s&&tc>=lc+s)
		devide(lr,lc+s,tr,tc,s);
	else
	{
		qp[lr+s-1][lc+s]=no;
		devide(lr,lc+s,lr+s-1,lc+s,s);
	}//右上角棋盘 
	
	if(tr>=lr+s&&tc<lc+s)
		devide(lr+s,lc,tr,tc,s);
	else
	{
		qp[lr+s][lc+s-1]=no;
		devide(lr+s,lc,lr+s,lc+s-1,s);
	}//左下角棋盘 
	
	if(tr>=lr+s&&tc>=lc+s)
		devide(lr+s,lc+s,tr,tc,s);
	else
	{
		qp[lr+s][lc+s]=no;
		devide(lr+s,lc+s,lr+s,lc+s,s);
	}//右下角棋盘 
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
