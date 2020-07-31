/* CCF201604-4 ��Ϸ */  
  
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
  
        // �����յ������  
        if(front.row == n && front.col == m)  
            return front.level;  
  
        for(int i=0; i<DIRECTSIZE; i++) {  
            // �ƶ�һ��  
            v.row = front.row + direct[i].drow;  
            v.col = front.col + direct[i].dcol;  
            v.level = front.level + 1;  
  
            // ����Խ��������  
            if(v.row < 1 || v.row > n || v.col < 1 || v.col > m)  
                continue;  
  
            // �Ѿ����ʹ��ĵ㲻�ٷ���  
            if(visited[v.row][v.col][v.level])  
                continue;  
  
            // ��ǰ���������v��Ϊ�Ѿ����ʹ���v����������  
            visited[v.row][v.col][v.level] = 1;  
            q.push(v);  
        }  
    }  
  
    return 0;  
}  
  
int main()  
{  
    int n, m, t, r, c, a, b;  
  
    // ������ʼ��  
    memset(visited, 0, sizeof(visited));  
  
    // ��������  
    cin >> n >> m >> t;  
    for(int i=1; i<=t; i++) {  
        cin >> r >> c >> a >> b;  
  
        // ���÷���Σ��ʱ�䣬ʹ֮��Щʱ�䲻�ɽ���  
        for(int j=a; j<=b; j++)  
            visited[r][c][j] = 1;  
    }  
  
    // BFS����  
    int ans = bfs(n, m);  
  
    // ������  
    cout << ans << endl;  
  
    return 0;  
}  
