#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn=110;
vector<int> node[maxn];
int cnt[maxn]={0};
int high=1;

void DFS(int t,int h)
{
	high=max(high,h);
	if(node[t].size()==0)
	{
		cnt[h]++;
		return;
	}
	for(int i=0;i<node[t].size();i++)
		DFS(node[t][i],h+1);
}

int main()
{
	int n,m,id,k,c;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&id,&k);
		for(int j=0;j<k;j++)
		{
			scanf("%d",&c);
			node[id].push_back(c);
		}
	}
	DFS(1,1);
	printf("%d",cnt[1]);
	for(int i=2;i<=high;i++)
		printf(" %d",cnt[i]);
	printf("\n");
	return 0;
}
