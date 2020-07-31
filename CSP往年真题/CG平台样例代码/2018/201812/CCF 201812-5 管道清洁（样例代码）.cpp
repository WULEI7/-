#include <stdio.h>
#include <queue>
#include <string.h>

using namespace std;

const int N = 5010, M = 200010;
const int inf = 0x3f3f3f3f;
int ver[M], edge[M], cost[M], Next[M], head[M];
int ver_pre[M];//调试用
int d[N], incf[N], pre[N], v[N];//spfa算法
int n, k, tot, s, t, maxflow, ans;
int m, du[N];//下界补边要用
int cnt;//记录下界和
int num;//通过下界的费用，由于上下界的转换，算法里面并没有计算到这里的费用

void add(int x, int y, int z, int c){
    //x->y
    ver[++tot]=y, edge[tot]=z, cost[tot]=c;
    ver_pre[tot] = x;
    Next[tot]=head[x], head[x]=tot;
    //y->x
    ver[++tot]=x, edge[tot]=0, cost[tot]=-c;
    ver_pre[tot] = y;
    Next[tot]=head[y], head[y]=tot;
}

bool spfa()
{
    queue<int> q;
    memset(d, 0x3f, sizeof(d));//dist数组  inf
    memset(v, 0, sizeof(v));//是否在队列中
    q.push(s);
    d[s] = 0;
    v[s] = 1;
     incf[s] = 1<<30;
    while(!q.empty()){
        int x = q.front(); q.pop(); v[x] = 0;
        for (int i = head[x]; i; i = Next[i]){
            if (edge[i]){
                int y = ver[i];
                if (d[y] > d[x]+cost[i]){
                    d[y] = d[x]+cost[i];
                    incf[y] = min(incf[x], edge[i]);
                    pre[y] = i;
                    if (!v[y]){
                        v[y] = 1;
                        q.push(y);
                    }
                }
            }
        }

    }
    if (d[t] == 0x3f3f3f3f) return false;
    else return true;
}

void update()
{
    int x = t;
    while (x != s){
        int i =pre[x];
        edge[i] -= incf[t];
        edge[i^1] += incf[t];
        x = ver[i^1];
    }
    maxflow += incf[t];
    ans += d[t]*incf[t];
}


int main(int argc, char* argv[])
{
    char* file = (char*)"ccf3.txt";
    if(argc==2) file = argv[1];
    //freopen(file, "r", stdin);

    int T, S, E;
    scanf("%d%d%d", &T, &S, &E);
    while(T--){
        scanf("%d%d", &n, &m);
        s = 0, t = n+1;
        tot = 1;
        cnt = 0;
        maxflow = 0;
        num = 0;
        ans = 0;
        memset(head, 0, sizeof(head));
        memset(du, 0, sizeof(du));
        for(int i=1; i<=m; i++){
            int u,v; char t;
            scanf("%d %d %c", &u, &v, &t);
            getchar();
            switch(t){
                case 'A':
                    add(u,v,inf,E);
                    du[u]--,du[v]++;//原本上下界为(1,inf),调整为(1,inf-1或inf)后会出现流量不守恒，所以要补边，同时由于下界为1,所以du只加了1
                    num+=E;
                    break;
                case 'B':
                    //原本流量上下界是(1,1),但是调整后变成了(0,0)
                    //add(u,v,0,E);//由于上界为0,所以其实可以删除此边
                    du[u]--,du[v]++;
                    num+=E;
                    break;
                case 'C'://下界本身就为0
                    add(u,v,inf,E);
                    break;
                case 'D':
                    add(u,v,1,E);
                    break;
            }
        }
        for(int i=1; i<=n; i++){
            if(du[i] > 0){
                cnt += du[i];//计算s的出流总和
                add(s,i,du[i],0);
            }else if(du[i] < 0){
                add(i,t,-du[i],0);
            }
        }

        while (spfa())
            update();
        if(maxflow==cnt) printf("%d\n", ans+num);
        else printf("%d\n", -1);
    }


    return 0;
}

