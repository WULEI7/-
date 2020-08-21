#include <stdio.h>
#include <queue>
#include <string.h>

using namespace std;

const int N = 5010, M = 200010;
const int inf = 0x3f3f3f3f;
int ver[M], edge[M], cost[M], Next[M], head[M];
int ver_pre[M];//������
int d[N], incf[N], pre[N], v[N];//spfa�㷨
int n, k, tot, s, t, maxflow, ans;
int m, du[N];//�½粹��Ҫ��
int cnt;//��¼�½��
int num;//ͨ���½�ķ��ã��������½��ת�����㷨���沢û�м��㵽����ķ���

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
    memset(d, 0x3f, sizeof(d));//dist����  inf
    memset(v, 0, sizeof(v));//�Ƿ��ڶ�����
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
                    du[u]--,du[v]++;//ԭ�����½�Ϊ(1,inf),����Ϊ(1,inf-1��inf)�������������غ㣬����Ҫ���ߣ�ͬʱ�����½�Ϊ1,����duֻ����1
                    num+=E;
                    break;
                case 'B':
                    //ԭ���������½���(1,1),���ǵ���������(0,0)
                    //add(u,v,0,E);//�����Ͻ�Ϊ0,������ʵ����ɾ���˱�
                    du[u]--,du[v]++;
                    num+=E;
                    break;
                case 'C'://�½籾���Ϊ0
                    add(u,v,inf,E);
                    break;
                case 'D':
                    add(u,v,1,E);
                    break;
            }
        }
        for(int i=1; i<=n; i++){
            if(du[i] > 0){
                cnt += du[i];//����s�ĳ����ܺ�
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

