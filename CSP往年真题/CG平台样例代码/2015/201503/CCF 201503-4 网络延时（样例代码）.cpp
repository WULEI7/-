/* CCF201503-4 网络延时 */  
  
#include <iostream>  
#include <vector>  
#include <cstring>  
  
using namespace std;  
  
// 深度优先搜索：计算结点now到各个结点的距离，结果放入数组d[]中  
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
  
    // 输入数据，构建树（邻接图）  
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
  
    // 求结点1到各个结点的距离：距离放在数组dist[]中，dist[i]中存放结点1到结点i的距离  
    memset(dist, 0, sizeof(dist));  
    dfs(1, 0, dist, tree);  
  
    // 找出距离结点1最远的结点start  
    int start = 0;  
    dist[start] = 0;  
    for(int i=1; i<n+m+2; i++)  
        if(dist[i] > dist[start])  
            start = i;  
  
    // 求start结点到各个结点的距离：距离放在数组dist[]中，dist[i]中存放结点start到结点i的距离  
    memset(dist, 0, sizeof(dist));  
    dfs(start, 0, dist, tree);  
  
    // 找出距离结点start最远的结点target  
    int target = 0;  
    for (int i=1; i<n+m+2; i++)  
        if(dist[i] > dist[target])  
            target = i;  
  
    // 输出结果  
    cout << dist[target] << endl;  
  
    return 0;  
} 
