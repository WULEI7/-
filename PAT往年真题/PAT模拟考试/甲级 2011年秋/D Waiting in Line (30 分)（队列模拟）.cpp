#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
int n,m,k,q,a,t[1005],ans[1005];
struct node
{
	int poptime,endtime;//��һ���˳���ʱ�䣬���һ���˽���ʱ�� 
	queue<int> que;//���� 
}w[25];//���� 
int main()
{
	int index=0;//��ǰ����Ŀͻ���� 
	cin>>n>>m>>k>>q;
	for(int i=0;i<k;i++)
		cin>>t[i];
	for(int i=0;i<n;i++)
		w[i].poptime=w[i].endtime=0;//��ʼ��ʱ�� 
	for(int i=0;i<min(n*m,k);i++)
	{
		w[index%n].que.push(index);
		w[index%n].endtime+=t[index];
		if(index<n)
			w[index].poptime=t[index];
		ans[index]=w[index%n].endtime;
		index++;
	}
	for(;index<k;index++)
	{
		int temp=0,mint=1999999999;
		for(int i=0;i<n;i++)
		{
			if(w[i].poptime<mint)
			{
				mint=w[i].poptime;
				temp=i;
			}
		}//�ҵ����ճ�λ�õĴ����Ŷӣ����ͬʱ�ճ���Ĭ����ǰ�Ĵ������� 
		w[temp].que.pop();
		w[temp].que.push(index);
		w[temp].poptime+=t[w[temp].que.front()];
		w[temp].endtime+=t[index];
		ans[index]=w[temp].endtime;
	}
	for(int i=0;i<q;i++)
	{
		cin>>a;
		a--;//�±��0��ʼ 
		if(ans[a]-t[a]<540)
			printf("%02d:%02d\n",ans[a]/60+8,ans[a]%60);//ע��ʱ�����8�� 
		else
			printf("Sorry\n");
	}
	return 0;
}
