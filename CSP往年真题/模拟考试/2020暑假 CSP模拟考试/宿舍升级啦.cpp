#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
int num[105][2],xue[105][8];
int main()
{
	int t;
	cin>>t;
	for(int T=1;T<=t;T++)
	{
		printf("Case %d:\n",T);
		memset(num,0,sizeof(num));
		memset(xue,0,sizeof(xue));
		queue<int> q;
		int m,n,k,x,sum=0;//ѧ������sum 
		cin>>m;
		for(int i=1;i<=m;i++)
		{
			cin>>n>>k;
			num[i][0]=n;//������ 
			num[i][1]=7-k;//����������� 
			sum+=k;//������ 
			for(int j=1;j<=k;j++)
			{
				cin>>xue[i][j];
			}
		}
		int tot;//��Ҫ���������� 
		if(sum%7)
			tot=sum/7+1;
		else
			tot=sum/7;
		for(int i=1;i<=tot;i++)
		{
			if(num[i][1]>0)
				q.push(i);
		}
		int pos=tot+1,temp=1;//��ǰ������pos��ѧ�����е�������ǰѧ���ǵ�ǰ����ĵ�temp�� 
		while(pos<=m)
		{
			if(xue[pos][temp]>0)
			{
				printf("%d %d\n",xue[pos][temp],num[q.front()][0]);
				temp++;
				num[q.front()][1]--;
			}
			else
			{
				pos++;
				temp=1;
			}
			if(num[q.front()][1]==0)
				q.pop();
		}
	}
	return 0;
}
