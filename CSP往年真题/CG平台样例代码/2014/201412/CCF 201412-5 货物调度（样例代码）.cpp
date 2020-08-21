#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false)
#define maxn 805
#define maxm 50005
#define INF 200000005
#define ll long long

struct ZKW
{
    int s, t, n;
    int cost;
    bool vis[maxn];
    int dist[maxn];
    //vis两个用处：spfa里的访问标记，増广时候的访问标记，dist是每个点的距离标号
    int nedge, p[maxm], c[maxm], cc[maxm], nex[maxm], head[maxn];
    //p[i]表示以某一点出发的编号为i的边对应点，c表示编号为i的边的流量，cc表示编号为i的边的费用
    void addedge(int x, int y, int z, int zz)//x->y 流量 费用
    {
        p[++nedge] = y, c[nedge] = z, cc[nedge] = zz, nex[nedge] = head[x], head[x] = nedge;
        p[++nedge] = x, c[nedge] = 0, cc[nedge] = -zz, nex[nedge] = head[y], head[y] = nedge;
    }

    void init(int n, int s, int t)//传入有多少个点，起点及终点
    {
        this->n = n, this->s = s, this->t = t;
        memset(nex, -1, sizeof nex);
        memset(head, -1, sizeof head);
        cost = 0, nedge = -1;
    }

    bool spfa(int s, int t)
    {
        memset(vis, 0, sizeof vis);
        for (int i = 0; i <= n; i++)dist[i] = INF;
        dist[t] = 0;
        vis[t] = 1;
        deque<int>q;
        q.push_back(t);
        while (!q.empty())
        {
            int now = q.front();
            q.pop_front();
            for (int k = head[now]; k>-1; k = nex[k])if (c[k ^ 1] && dist[p[k]]>dist[now] - cc[k])
                {
                    dist[p[k]] = dist[now] - cc[k];
                    if (!vis[p[k]])
                    {
                        vis[p[k]] = 1;
                        if (!q.empty() && dist[p[k]]<dist[q.front()])q.push_front(p[k]);
                        else q.push_back(p[k]);
                    }
                }
            vis[now] = 0;
        }
        return dist[s]<INF;
    }

    int dfs(int x, int low)
    {
        //这里就是进行増广了
        if (x == t)
        {
            vis[t] = 1;
            return low;
        }
        int used = 0, a;
        vis[x] = 1;
        //这边是不是和dinic很像啊
        for (int k = head[x]; k>-1; k = nex[k])if (!vis[p[k]] && c[k] && dist[x] - cc[k] == dist[p[k]])
            {
                //这个条件就表示这条边可以进行増广
                a = dfs(p[k], min(c[k], low - used));
                if (a)cost += a * cc[k], c[k] -= a, c[k ^ 1] += a, used += a;
                //累加答案，加流等操作都在这了
                if (used == low)break;
            }
        return used;
    }
    int costflow()
    {
        int flow = 0;
        while (spfa(s, t))
        {
            //判断起点终点是否连通，不连通说明满流，做完了退出
            vis[t] = 1;
            while (vis[t])
            {
                memset(vis, 0, sizeof vis);
                flow += dfs(s, INF);
                //一直増广直到走不到为止（这样也可以省时间哦）
            }
        }
        return flow;//这里返回的是最大流，费用的答案在cost里
    }
} G;

int main()
{
    int n,m;
    cin>>n>>m;
    int st=0,ed=n*7+2;
    G.init(7*n+5,st,ed);

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=7;j++)
        {
            int x;
            cin>>x;
            G.addedge(st,(i-1)*7+j,x,0);
        }

        for(int j=1;j<=7;j++)
        {
            int x;
            cin>>x;
            G.addedge((i-1)*7+j,ed,x,0);
        }

        int v,w;
        cin>>v>>w;
        for(int j=1;j<=6;j++)
            G.addedge((i-1)*7+j,(i-1)*7+j+1,v,w);
        G.addedge((i-1)*7+7,(i-1)*7+1,v,w);
    }

    for(int i=0;i<m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        for(int i=1;i<=7;i++)
        {
            G.addedge((x-1)*7+i,(y-1)*7+i,INF,z);
            G.addedge((y-1)*7+i,(x-1)*7+i,INF,z);
        }
    }

    G.costflow();
    cout<<G.cost;
    return 0;
}


