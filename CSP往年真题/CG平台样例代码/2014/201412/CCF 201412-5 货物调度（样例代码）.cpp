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
    //vis�����ô���spfa��ķ��ʱ�ǣ�����ʱ��ķ��ʱ�ǣ�dist��ÿ����ľ�����
    int nedge, p[maxm], c[maxm], cc[maxm], nex[maxm], head[maxn];
    //p[i]��ʾ��ĳһ������ı��Ϊi�ı߶�Ӧ�㣬c��ʾ���Ϊi�ıߵ�������cc��ʾ���Ϊi�ıߵķ���
    void addedge(int x, int y, int z, int zz)//x->y ���� ����
    {
        p[++nedge] = y, c[nedge] = z, cc[nedge] = zz, nex[nedge] = head[x], head[x] = nedge;
        p[++nedge] = x, c[nedge] = 0, cc[nedge] = -zz, nex[nedge] = head[y], head[y] = nedge;
    }

    void init(int n, int s, int t)//�����ж��ٸ��㣬��㼰�յ�
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
        //������ǽ��Љ�����
        if (x == t)
        {
            vis[t] = 1;
            return low;
        }
        int used = 0, a;
        vis[x] = 1;
        //����ǲ��Ǻ�dinic����
        for (int k = head[x]; k>-1; k = nex[k])if (!vis[p[k]] && c[k] && dist[x] - cc[k] == dist[p[k]])
            {
                //��������ͱ�ʾ�����߿��Խ��Љ���
                a = dfs(p[k], min(c[k], low - used));
                if (a)cost += a * cc[k], c[k] -= a, c[k ^ 1] += a, used += a;
                //�ۼӴ𰸣������Ȳ�����������
                if (used == low)break;
            }
        return used;
    }
    int costflow()
    {
        int flow = 0;
        while (spfa(s, t))
        {
            //�ж�����յ��Ƿ���ͨ������ͨ˵���������������˳�
            vis[t] = 1;
            while (vis[t])
            {
                memset(vis, 0, sizeof vis);
                flow += dfs(s, INF);
                //һֱ����ֱ���߲���Ϊֹ������Ҳ����ʡʱ��Ŷ��
            }
        }
        return flow;//���ﷵ�ص�������������õĴ���cost��
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


