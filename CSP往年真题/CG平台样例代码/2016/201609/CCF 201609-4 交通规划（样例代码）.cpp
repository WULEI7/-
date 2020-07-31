#include <iostream>
#include <queue>
#include <vector>
#define NMAX 10005
#define INTMAX 0x7fffffff
using namespace std;
// v��ʾ�ڵ㣬cost��ʾ�����㵽v��ľ���
struct Node
{
    int v;
    int cost;
    Node(int vv = 0, int c = 0)
    {
        v = vv, cost = c;
    }
    // ���ȶ��н��������С��������
    friend bool operator<(Node n1, Node n2)
    {
        return n1.cost > n2.cost;
    }
};
// v��ʾ�ߵ���һ�˽ڵ㣬cost��ʾ�ñߵ�Ȩ��
struct Edge
{
    int v;
    int cost;
    Edge(int vv = 0, int c = 0)
    {
        v = vv, cost = c;
    }
};
vector<Edge>G[NMAX];    // ����ͼ
int disto[NMAX];        // �����㵽ĳ�����
int costo[NMAX];        // ��ͨ�õ���Ҫ���ӵıߵ�Ȩ��
int N, M;
void dijkstra(int s)
{
    for (int i = 0; i <= N; i++)
    {
        costo[i] = disto[i] = INTMAX;
    }
    disto[s] = 0;
    costo[s] = 0;
    priority_queue<Node>pq;     // ����<v,disto[v]>�Ұ�disto[v]��������
    pq.push(Node(s, 0));
    Node tmp;
    while (!pq.empty())
    {
        tmp = pq.top();
        pq.pop();
        int v = tmp.v;
        int len = G[v].size();
        for (int i = 0; i < len; i++)
        {
            int vv = G[v][i].v;
            int cost = G[v][i].cost;
            int newdist = disto[v] + cost;
            if (disto[vv] > newdist)
            {
                disto[vv] = newdist;
                costo[vv] = cost;   // ���ӵ�����
                pq.push(Node(vv, disto[vv]));
            }
            // ���ӵ�����
            // �����vvʱ�����ֶ��־�����ͬ�ķ�����ѡȡ�±���С�Ǹ�
            if (disto[vv] == newdist)
            {
                costo[vv] = min(costo[vv], cost);
            }
        }
    }
}
int main(void)
{
    cin >> N >> M;
    int s, e, c;
    for (int i = 0; i < M; i++)
    {
        cin >> s >> e >> c;
        G[s].push_back(Edge(e, c));
        G[e].push_back(Edge(s, c));
    }
    dijkstra(1);
    // ͳ�Ʊ�Ȩ��
    int res = 0;
    for (int i = 2; i <= N; i++)
    {
        res += costo[i];
    }
    cout << res << endl;
    return 0;
}


