/* CCF201503-4 ������ʱ */  
  
#include <iostream>  
#include <vector>  
#include <cstring>  
  
using namespace std;  
  
// �������������������now���������ľ��룬�����������d[]��  
void dfs(int now, int last, int d[], vector<int> tree[])  
{  
    int u, size;  
    size = tree[now].size();  
    for(int i=0; i<size; i++)  
        if ((u = tree[now][i]) != last) {  
            d[u] = d[now] + 1;  
            dfs(u, now, d, tree);  
        }  
}  
  
int main()  
{  
    int n, m, t;  
  
    // �������ݣ����������ڽ�ͼ��  
    cin >> n >> m;  
  
    vector<int> tree[n+m+2];  
    int dist[n+m+2];  
  
    for(int i=2; i<=n; i++) {  
        cin >> t;  
  
        tree[i].push_back(t);  
        tree[t].push_back(i);  
    }  
    for(int i=1; i<=m; i++) {  
        cin >> t;  
  
        tree[n+i].push_back(t);  
        tree[t].push_back(n+i);  
    }  
  
    // ����1���������ľ��룺�����������dist[]�У�dist[i]�д�Ž��1�����i�ľ���  
    memset(dist, 0, sizeof(dist));  
    dfs(1, 0, dist, tree);  
  
    // �ҳ�������1��Զ�Ľ��start  
    int start = 0;  
    dist[start] = 0;  
    for(int i=1; i<n+m+2; i++)  
        if(dist[i] > dist[start])  
            start = i;  
  
    // ��start��㵽�������ľ��룺�����������dist[]�У�dist[i]�д�Ž��start�����i�ľ���  
    memset(dist, 0, sizeof(dist));  
    dfs(start, 0, dist, tree);  
  
    // �ҳ�������start��Զ�Ľ��target  
    int target = 0;  
    for (int i=1; i<n+m+2; i++)  
        if(dist[i] > dist[target])  
            target = i;  
  
    // ������  
    cout << dist[target] << endl;  
  
    return 0;  
} 
