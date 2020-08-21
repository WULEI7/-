#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
const int N = 20005;
int n,m,len[N];
bool vis[N];
vector<int> v[N];
void bfs(){
	queue<int> q;
	q.push(1);
	int cur;
	while(!q.empty()){
		cur = q.front();
		q.pop();
		for(int i = 0; i < v[cur].size(); i++){
			int x = v[cur][i];
			if(vis[x]) continue;
			vis[x] = true;
			q.push(x);
		}
	}
	q.push(cur);
	memset(vis, false, sizeof(vis));
	while(!q.empty()){
		cur = q.front();
		q.pop();
		for(int i = 0; i < v[cur].size(); i++){
			int x = v[cur][i];
			if(vis[x]) continue;
			vis[x] = true;
			len[x] = len[cur]+1;
			q.push(x);
		}
	}
	printf("%d\n", len[cur]);
}
int main()
{
//	freopen("10.out","w",stdout);
//	freopen("10.in","r",stdin);	
	int x;
	scanf("%d%d", &n, &m);
	for(int i = 2; i <= n+m; i++){
		scanf("%d", &x);
		v[i].push_back(x);
		v[x].push_back(i);
	}
	bfs();
	return 0;
}


