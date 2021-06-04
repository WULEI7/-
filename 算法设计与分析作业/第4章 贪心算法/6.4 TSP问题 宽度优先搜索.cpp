#include <iostream>
#include <cstdio>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
const int INF=1000000000;//无穷大 
int n;//顶点个数 
double g[1005][1005];//邻接矩阵 
double bestcost=INF;//记录最优值 
vector<int> bestpath;//记录最优路径 

struct node
{
	vector<int> path;
	double cost;
	void printpath()
	{
		int size=path.size();
		cout<<path[0];
		for(int i=1;i<size;i++)
			cout<<"->"<<path[i];
		cout<<endl;
	}
};

void TSP_DFS()
{
	int time=0;
	queue<node> open;//open表 
	open.push({{1},0});//起始节点入栈 
	while(!open.empty())
	{
		node cur=open.front();
		open.pop();
		time++;
		if(time<=20)
			cur.printpath();//打印当前路径 
		if(cur.cost>=bestcost)
			continue;
		if(int(cur.path.size())==n)//cur为叶子结点 
		{
			double totcost=cur.cost+g[1][cur.path[cur.path.size()-1]];
			if(totcost<bestcost)//检测是否是更优解，更新最优解 
			{
				bestcost=totcost;
				bestpath=cur.path;
			}
		}
		else//cur不是叶子结点 
		{
			vector<int> curpath=cur.path;
			double curcost=cur.cost;
			for(int i=1;i<=n;i++)//生成所有满足条件的子节点，加入open中 
			{
				if(find(curpath.begin(),curpath.end(),i)==curpath.end())
				{
					curcost+=g[curpath[curpath.size()-1]][i];
					curpath.push_back(i);
					if(curcost<bestcost)
						open.push({curpath,curcost});
					curpath.pop_back();
					curcost-=g[curpath[curpath.size()-1]][i];
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		cin>>g[i][j];
		if(g[i][j]==0)
			g[i][j]=INF;
	}
	TSP_DFS();
	cout<<bestcost<<": "<<bestpath[0];
	int size=bestpath.size();
	for(int i=1;i<size;i++)
		cout<<"->"<<bestpath[i];
	cout<<endl;
	return 0;
}
