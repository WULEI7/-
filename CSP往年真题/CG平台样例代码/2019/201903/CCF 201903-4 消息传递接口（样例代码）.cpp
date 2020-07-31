#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
using namespace std;
int T, n;
const int maxn = 11005;
string task[maxn][9];
int pos[maxn];//进程执行到的位置
int res = 0;
int findnum(string &s) {//找到指令后面的编号
    int p = 1, n = s.size(), ans = 0;
    while (p < n) {
        ans = ans * 10 + s[p++] - '0';
    }
    return ans;
}
bool match(int cur) {//执行cur号进程能否成功
    string s = task[cur][pos[cur]];
    if (!s.size())    return false;//s为空说明遍历到指令末尾了
    int p = findnum(s);//与之通信的进程
    if (!task[p][pos[p]].size() || findnum(task[p][pos[p]]) != cur)    return false;
    if (s[0] == task[p][pos[p]][0])    return false;
    pos[cur]++, pos[p]++;
    res -= 2;//总指令数-2
    if (p < cur)    while (match(p));//已经遍历过的进程指针发生了移动
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin >> T >> n;
    cin.get();
    while (T--) {
        string s, str;
        res = 0;
        for (int i = 0; i < n; i++) {
            getline(cin, s);
            int p = 0, q = 0;
            while (p < s.size()) {
                if (s[p] == ' ') {
                    task[i][q++] = str;
                    str.clear();
                }
                else
                {
                    str += s[p];
                }
                p++;
            }
            task[i][q] = str;
            str.clear();
            res += q + 1;
        }
        for (int i = 0; i < n; i++) {
            while (match(i));//返回true继续执行，减少递归深度
        }
        
        if (res)    cout << "1" << endl;
        else
        {
            cout << "0" << endl;
        }
        for (int i = 0; i < n; i++) {
            fill(task[i], task[i] + sizeof(task[i]), "");//执行完一组程序给二维数组置空
        }
        memset(pos, 0, sizeof pos);
    }
    return 0;
}

