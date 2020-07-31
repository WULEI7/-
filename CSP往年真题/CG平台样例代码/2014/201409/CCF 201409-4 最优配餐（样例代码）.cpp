/* CCF201409-4 最优配餐 */  
  
#include <iostream>  
#include <cstring>  
#include <queue>  
  
using namespace std;  
  
const int N = 1000;  
const int TRUE = 1;  
  
const int DIRECTSIZE = 4;  
struct direct {  
    int drow, dcol;  
} direct[DIRECTSIZE] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};  
  
int buyer[N+1][N+1];  
int visited[N+1][N+1];  
  
struct node {  
    int row, col, step;  
    node(){}  
    node(int r, int c, int s){row=r, col=c, step=s;}  
};  
  
queue<node> q;  
int buyercount = 0;  
long long ans = 0;  
  
void bfs(int n)  
{  
    node front, v;  
  
    while(!q.empty()) {  
        front = q.front();  
        q.pop();  
  
        for(int i=0; i<DIRECTSIZE; i++) {  
            // 移动一格  
            v.row = front.row + direct[i].drow;  
            v.col = front.col + direct[i].dcol;  
            v.step = front.step + 1;  
  
            // 行列越界则跳过  
            if(v.row < 1 || v.row > n || v.col < 1 || v.col > n)  
                continue;  
  
            // 已经访问过的点不再访问  
            if(visited[v.row][v.col])  
                continue;  
  
            // 如果是订餐点，则计算成本并且累加  
            if(buyer[v.row][v.col] > 0) {  
                visited[v.row][v.col] = 1;  
                ans += buyer[v.row][v.col] * v.step;  
                if(--buyercount == 0)  
                    return;  
            }  
  
            // 向前搜索：标记v点为已经访问过，v点加入队列中  
            visited[v.row][v.col] = 1;  
            q.push(v);  
        }  
    }  
}  
  
int main()  
{  
    int n, m, k, d, x, y, c;  
  
    // 变量初始化  
    memset(buyer, 0, sizeof(buyer));  
    memset(visited, 0, sizeof(visited));  
  
    // 输入数据  
    cin >> n >> m >> k >> d;  
    for(int i=1; i<=m; i++) {  
        cin >> x >> y;  
        q.push(node(x, y, 0));  
        visited[x][y] = TRUE;      // 各个分店搜索时，需要跳过  
    }  
    for(int i=1; i<=k; i++) {  
        cin >> x >> y;  
        cin >> c;  
        if(buyer[x][y] == 0)    // 统计客户所在地点数量：多个客户可能在同一地点  
            buyercount++;  
        buyer[x][y] += c;       // 统计某个地点的订单数量  
    }  
    for(int i=1; i<=d; i++) {  
        cin >> x >> y;  
        visited[x][y] = TRUE;  
    }  
  
    // BFS  
    bfs(n);  
  
    // 输出结果  
    cout << ans << endl;  
  
    return 0;  
}  
