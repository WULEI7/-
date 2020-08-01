#include <cstdio>
#include <cstring>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;
const double N = 1e6+10;
const double pi = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
#define ll long long
#define CL(a,b) memset(a,b,sizeof(a))
const int maxn = 1e3+24;
int n, m, ans = 0;
bool r[maxn][maxn], vis[maxn];
vector <int> e[maxn];
void read()
{
    cin >> n >> m;
    for(int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
    }
}
 
void dfs(int u, int v) //u为当前查找的点，v为直接或间接与u相连通的点
{
    r[u][v] = true; //u可以访问到v
    r[v][u] = true; //v可以访问到u
    vis[v] = true;
 
    for(int i = 0; i < e[v].size(); ++i)
        if(!vis[e[v][i]])
            dfs(u, e[v][i]);
}
 
void solve()
{
    for(int i = 1; i <= n; ++i)
    {
        memset(vis, 0, sizeof(vis));
        dfs(i, i); //搜索每个点，从自身开始查找
    }
 
    for(int i = 1; i <= n; ++i)
    {
        int cnt = 0;
        for(int j = 1; j <= n; ++j)
            if(r[i][j])
                cnt++;
        if(cnt == n)
            ans++;
    }
    cout << ans;
}
 
int main()
{
    read();
    solve();
    return 0;
}

