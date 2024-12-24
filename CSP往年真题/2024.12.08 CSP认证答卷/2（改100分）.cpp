#include <iostream>
#include <algorithm>
using namespace std;
int n, a[100005], b[100005], c[100005];
int main() {
    cin >> n;
    for (int i = 0; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    c[0] = a[0]; // 第一个区域的能量值
    for (int i = 1; i <= n; i++)// 计算累积能量值
        c[i] = c[i - 1] + a[i] - b[i];
    int g[n + 1];// 计算后缀最大值g(i)
    g[n] = c[n];
    for (int i = n - 1; i >= 0; i--)
        g[i] = max(g[i + 1], c[i]);
    for (int k = 1; k <= n; k++)// 计算每个区域发生意外时所需的最小初始能量
	{
        int w = max(g[0], g[k] + b[k]);
        cout << w << " ";
    }
    return 0;
}
