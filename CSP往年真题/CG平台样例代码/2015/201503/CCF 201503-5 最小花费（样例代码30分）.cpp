#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

struct Node {
    long long from, to, cost;
    Node (long long f, long long t, long long c) : from(f), to(t), cost(c) {}
};

const long long maxn = 100000 + 5;
long long n, m, cost[maxn];
vector<Node> G[maxn];
vector<long long> Path, path, Dis, dis; // Õæ¼Ùpath
bool vis[maxn];

void DFS(long long from, long long to)
{
    if (from == to) {
        Path = path;
        Dis = dis;
        return;
    }
    for (long long i = 0, v, d; i < G[from].size(); ++i) {
        v = G[from][i].to;
        d = G[from][i].cost;
        if (vis[v]) continue;
        vis[v] = true;
        path.push_back(v);
        dis.push_back(d);
        DFS(v, to);
        path.pop_back();
        dis.pop_back();
    }
}

int main()
{
	
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (long long i = 1; i <= n; ++i)
        cin >> cost[i];
    for (long long i = 1, u, v, c; i < n; ++i) {
        cin >> u >> v >> c;
        G[u].push_back(Node(u, v, c));
        G[v].push_back(Node(v, u, c));
    }
    for (long long i = 0, from, to; i < m; ++i) {
        cin >> from >> to;
        memset(vis, 0, sizeof(vis));
        path.clear();
        dis.clear();
        path.push_back(from);
        vis[from] = true;
        DFS(from, to);
        long long _min = cost[from], cos = 0, ans = 0;
        for (long long i = 0; i < Path.size() - 1; ++i) {
            if (cost[Path[i]] < _min) {
                ans += cos*_min;
                cos = 0;
                _min = cost[Path[i]];
            }
            cos += Dis[i];
        }
        ans += _min*cos;
        cout << ans << endl;
    }
}

