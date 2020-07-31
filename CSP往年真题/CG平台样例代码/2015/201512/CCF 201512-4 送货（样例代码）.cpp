#include <algorithm>
#include <cstring>
#include <vector>
#include <stack>
#include <fstream>
using namespace std;

const int maxn = 10000 + 10;
const int maxm = 100000 + 10;

vector<int> g[maxn];
int  deg[maxn];
bool vis[maxn], visEdge[maxn][maxn];
int  n, m;
stack<int> ans;

void dfs(int u)
{
    vis[u] = 1;
    for(int i = 0; i < (int)g[u].size(); ++i)
    {
        int v = g[u][i];
        if(!visEdge[u][v]){
            visEdge[u][v] = visEdge[v][u] = 1;
            dfs(v);
            ans.push(v);
        }
    }
}

int main()
{
#ifdef LOCAL
freopen("data.in", "r", stdin);
#endif // LOCAL

    scanf("%d %d", &n, &m);
    int a, b;

    for(int i = 1; i <= m; ++i){
        scanf("%d %d", &a, &b);
        deg[a]++, deg[b]++;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    //保证是字典序最小的
    for(int i = 1; i <= n; ++i){
        sort(g[i].begin(), g[i].end());
    }

    int cnt = 0;
    for(int i = 1; i <= n; ++i){
        if(deg[i] & 1) cnt++;
    }
    // 如果存在奇度数的顶点，顶点1必须是奇度数的
    if(cnt == 2 && !(deg[1] & 1)){
        printf("-1\n");
        return 0;
    }

    if(cnt == 2 || cnt == 0){
        dfs(1);
        for(int i = 1; i <= n; ++i){
            if(!vis[i]){
                printf("-1\n");
                return 0;
            }
        }

        printf("1");
        while(!ans.empty()){
            printf(" %d", ans.top());
            ans.pop();
        }
    }
    else{
        printf("-1\n");
    }

    return 0;
}


