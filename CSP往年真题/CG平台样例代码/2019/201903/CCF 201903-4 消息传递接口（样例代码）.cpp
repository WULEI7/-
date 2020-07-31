#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
using namespace std;
int T, n;
const int maxn = 11005;
string task[maxn][9];
int pos[maxn];//����ִ�е���λ��
int res = 0;
int findnum(string &s) {//�ҵ�ָ�����ı��
    int p = 1, n = s.size(), ans = 0;
    while (p < n) {
        ans = ans * 10 + s[p++] - '0';
    }
    return ans;
}
bool match(int cur) {//ִ��cur�Ž����ܷ�ɹ�
    string s = task[cur][pos[cur]];
    if (!s.size())    return false;//sΪ��˵��������ָ��ĩβ��
    int p = findnum(s);//��֮ͨ�ŵĽ���
    if (!task[p][pos[p]].size() || findnum(task[p][pos[p]]) != cur)    return false;
    if (s[0] == task[p][pos[p]][0])    return false;
    pos[cur]++, pos[p]++;
    res -= 2;//��ָ����-2
    if (p < cur)    while (match(p));//�Ѿ��������Ľ���ָ�뷢�����ƶ�
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
            while (match(i));//����true����ִ�У����ٵݹ����
        }
        
        if (res)    cout << "1" << endl;
        else
        {
            cout << "0" << endl;
        }
        for (int i = 0; i < n; i++) {
            fill(task[i], task[i] + sizeof(task[i]), "");//ִ����һ��������ά�����ÿ�
        }
        memset(pos, 0, sizeof pos);
    }
    return 0;
}

