#include<iostream>
#include<vector>
#define ll long long
#define IO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int maxn = 5e4 + 50;
int n, m, k;
bool isimp[maxn];
vector< vector< pair <int, int> > > tree;
vector< vector<ll> > dp;
void dfs(int u, int fa)
{
    vector<ll>& cur = dp[u]; cur[0] = 0;
    for (const auto& pr : tree[u])
        if (pr.first != fa)
        {
            dfs(pr.first, u);
            vector<ll>& sub = dp[pr.first];
            for (int x = k; x > 0; --x)
                for (int y = x; y >= 0; --y)
                    if (cur[y] != -1 && sub[x - y] != -1)
                    {
                        ll t = cur[y] + sub[x - y] + (ll)pr.second * (x - y) * (k - x + y);
                        if (cur[x] == -1 || cur[x] > t) cur[x] = t;
                    }
        }
    if (isimp[u])
        for (int i = k; i > 0; --i)
            if (cur[i] == -1 || cur[i] > cur[i - 1])
                cur[i] = cur[i - 1];
}
int main()
{
    IO;
    cin >> n >> m >> k;
    for (int i = 0, x; i < m; i++)cin >> x, isimp[x] = true;
    tree.resize(n + 1);
    for (int i = 1; i < n; i++)
    {
        int u, v, w; cin >> u >> v >> w;
        tree[u].emplace_back(v, w);
        tree[v].emplace_back(u, w);
    }
    dp.resize(n + 1, vector<ll>(k + 1, -1));
    dfs(1, 0);
    cout << dp[1][k] << "\n";
    return 0;
}
