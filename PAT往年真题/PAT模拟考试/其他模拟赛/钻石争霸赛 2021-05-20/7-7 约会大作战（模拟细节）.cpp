#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
int n,m,q,x,y,a[105][105],b[105][105],lasta[105],lastb[105],maxna[105],maxnb[105],cnta[105],cntb[105],total=0;
map<pair<int,int>,int> cnt;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
		cin>>a[i][j];
	for(int i=1;i<=m;i++)
	for(int j=1;j<=n;j++)
		cin>>b[i][j];
	while(q--)//q��ѯ�� 
	{
		cin>>x>>y;
		cnt[{x,y}]++;
		//if(cnt[{x,y}]>1) while(1);
		//���ϲ���˵��ûͨ��������1��4�����ڡ����ͬһ���˱�ѯ�����Σ��ᱻ���������˴���������� 
		//if(cnt[{x,y}]==1)
		//����ͨ������0��1��3��������ͨ������0��2��3 
		{
			if(cnta[x]>=0)
				cnta[x]++;
			if(cntb[y]>=0)
				cntb[y]++;
		}
		if(cnta[x]<=2||cntb[y]<=2)//ǰ���α�ѯ�ʲ���� 
		{
			maxna[x]=max(lasta[x],a[x][y]);//���ºøж���ֵ 
			maxnb[y]=max(lastb[y],b[y][x]);
			lasta[x]=a[x][y];
			lastb[y]=b[y][x];
			continue;
		}
		else//�ӵ�����ѯ�ʿ�ʼ�����ѯ�ʵ��˵ĺøжȴ��������֮ǰ��������������Ϸ��û��ǣ�ֵ��ˣ�����ܣ�����ܾ� 
		{
			if(cnta[x]==-1||cntb[y]==-1)//����һ���Ѿ���Գɹ�������� 
			{
				//while(1);
				//˵��ûͨ��������1��4û�о��������֧ 
				/*
				maxna[x]=max(lasta[x],a[x][y]);//���ºøж���ֵ 
				maxnb[y]=max(lastb[y],b[y][x]);
				lasta[x]=a[x][y];
				lastb[y]=b[y][x];
				*/
				continue;
			}
			else if(a[x][y]>maxna[x]&&b[y][x]>maxnb[y])//���Ϻø�Ҫ����Գɹ� 
			{
				//cout<<"��Գɹ�";
				cout<<x<<" "<<y<<endl;
				total++;
				cnta[x]=-1;
				cntb[y]=-1;
			}
			/* 
			else//ע��if-else��֧ϸ�ڣ�����©��������� 
			{
				maxna[x]=max(lasta[x],a[x][y]);//���ºøж���ֵ 
				maxnb[y]=max(lastb[y],b[y][x]);
				lasta[x]=a[x][y];
				lastb[y]=b[y][x];
			}
			*/
			maxna[x]=max(lasta[x],a[x][y]);//���ºøж���ֵ 
			maxnb[y]=max(lastb[y],b[y][x]);
			lasta[x]=a[x][y];
			lastb[y]=b[y][x];
		}
	}
	if(total==0)
		cout<<"PTA is my only love"<<endl;
	return 0;
}
