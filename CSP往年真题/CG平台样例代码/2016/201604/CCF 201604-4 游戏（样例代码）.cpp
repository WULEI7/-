/* CCF201604-4 游戏 */  
  
#include <iostream>  
#include <cstring>  
#include <queue>  
  
using namespace std;  
  
const int N = 100;  
  
const int DIRECTSIZE = 4;  
struct direct {  
    int drow, dcol;  
} direct[DIRECTSIZE] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};  
  
int visited[N+1][N+1][300+1];  
  
struct node {  
    int row, col, level;  
};  
  
int bfs(int n, int m)  
{  
    node start, front, v;  
    start.row = 1;  
    start.col = 1;  
    start.level = 0;  
  
    queue<node> q;  
    q.push(start);  
  
    while(!q.empty()) {  
        front = q.front();  
        q.pop();  
  
        // 到达终点则结束  
        if(front.row == n && front.col == m)  
            return front.level;  
  
        for(int i=0; i<DIRECTSIZE; i++) {  
            // 移动一格  
            v.row = front.row + direct[i].drow;  
            v.col = front.col + direct[i].dcol;  
            v.level = front.level + 1;  
  
            // 行列越界则跳过  
            if(v.row < 1 || v.row > n || v.col < 1 || v.col > m)  
                continue;  
  
            // 已经访问过的点不再访问  
            if(visited[v.row][v.col][v.level])  
                continue;  
  
            // 向前搜索：标记v点为已经访问过，v点加入队列中  
            visited[v.row][v.col][v.level] = 1;  
            q.push(v);  
        }  
    }  
  
    return 0;  
}  
  
int main()  
{  
    int n, m, t, r, c, a, b;  
  
    // 变量初始化  
    memset(visited, 0, sizeof(visited));  
  
    // 输入数据  
    cin >> n >> m >> t;  
    for(int i=1; i<=t; i++) {  
        cin >> r >> c >> a >> b;  
  
        // 设置方格危险时间，使之那些时间不可进入  
        for(int j=a; j<=b; j++)  
            visited[r][c][j] = 1;  
    }  
  
    // BFS搜索  
    int ans = bfs(n, m);  
  
    // 输出结果  
    cout << ans << endl;  
  
    return 0;  
}  
