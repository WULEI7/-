#include<bits/stdc++.h>
#define ri register int
#define ll long long
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
const int maxn = 505;
struct edge{
	int v, nxt, type;
	ll w;
}E[200005];
int head[maxn], cnt = 0;
ll dis[maxn][2];
int vis[maxn][2];
int n, m;
inline void add(int u, int v, ll w, int t){
	E[++cnt].v = v;
	E[cnt].w = w;
	E[cnt].nxt = head[u];
	E[cnt].type = t;
	head[u] = cnt;
}//邻接表 
struct node{
	ll w, len;
	int pos, dx;
	bool operator <(const node &x)const{
		return x.w < w;
	}
}point;
priority_queue<node> q;//堆优化 
inline void dijkstra(){
	for(ri i = 1; i <= n; ++i)
		dis[i][0] = dis[i][1] = 1e18;
	dis[1][0] = dis[1][1] = 0;
	point.w = 0; 
	point.pos = 1;
	point.len = 0;
	point.dx = 0;
	q.push(point);
	while(!q.empty()){
		node tmp = q.top();
		q.pop();
		int x = tmp.pos, dx = tmp.dx;
		ll l = tmp.w, len = tmp.len;
		if(vis[x][dx])
			continue;
		vis[x][dx] = 1;
		for(ri i = head[x]; i; i = E[i].nxt){
			int y = E[i].v, type = E[i].type;
			ll w = E[i].w;
			if(type){
				ll c = len + w;
				ll now = l - len * len + c * c;//这条小路对疲劳值的贡献 
				if(now < dis[y][1]){
					dis[y][1] = now;
					if(!vis[y][1]){
						point.len = c;
						point.w = dis[y][1];
						point.pos = y;
						point.dx = 1;
						q.push(point);
					}
				}
			} 
			else{
				if(l + w <= dis[y][0]){
					dis[y][0] = l + w;
					if(!vis[y][0]){
						point.w = dis[y][0];
						point.pos = y;
						point.len = 0;
						point.dx = 0;
						q.push(point);
					}
				}
			}	
		}
	}
}
int main(){
//	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
	fast;
	cin >> n >> m;
	for(ri i = 1; i <= m; ++i){
		int t, a, b;
		ll c;
		cin >> t >> a >> b >> c;
		add(a, b, c, t);
		add(b, a, c, t);
	}
	dijkstra();
	cout << min(dis[n][0], dis[n][1]) << "\n";
	return 0;
}



