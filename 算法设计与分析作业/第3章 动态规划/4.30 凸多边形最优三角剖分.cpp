#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int n,w[100][100],m[100][100],s[100][100];
struct node
{
	int x,y;
}p[100];//�洢�������� 

int Weight(int i,int j,int k)//Ȩ�������˴�Ϊ��С�ҳ������ʷ� 
{
	return w[i][j]+w[i][k]+w[j][k];
}

void MinWeightTriangulation(int n,int m[][100],int s[][100])//��������ֵ 
{
	for(int i=1;i<=n;i++)
		m[i][i]=0;
	for(int r=2;r<=n;r++)
	{
		for(int i=1;i<=n-r+1;i++)
		{
			int j=i+r-1;
			m[i][j]=m[i+1][j]+Weight(i-1,i,j);
			s[i][j]=i;
			for(int k=i+1;k<j;k++)
			{
				int t=m[i][k]+m[k+1][j]+Weight(i-1,k,j);
				if(t<m[i][j])
				{
					m[i][j]=t;
					s[i][j]=k;
				}
			}
		}
	}
}

void Traceback(int i,int j,int s[][100])//�������������ʷ� 
{
	if(i==j) return;
	Traceback(i,s[i][j],s);
	Traceback(s[i][j]+1,j,s);
	cout<<i-1<<s[i][j]<<j<<endl;
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>p[i].x>>p[i].y;
	for(int i=0;i<n;i++)
		w[i][i]=0;
	for(int i=0;i<n;i++)
	for(int j=i+1;j<n;j++)
	{
		int disx=p[i].x-p[j].x;
		int disy=p[i].y-p[j].y;
		w[i][j]=sqrt(disx*disx+disy*disy);
	}//����i������j�ľ��� 
	MinWeightTriangulation(n,m,s);//��������ֵ 
	Traceback(1,n-1,s);//�������������ʷ� 
	return 0;
}
