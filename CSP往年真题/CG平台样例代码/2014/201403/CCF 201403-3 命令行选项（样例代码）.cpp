#include <cstdio>
#include <string>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <cstring>
#include <set>
#include <queue>
#include <algorithm>
#include <vector>
#include <map>
#include <cctype>
#include <cmath>
#include <stack>
#include <list>
#include <sstream>
#define frer freopen("in.txt", "r", stdin)
#define frew freopen("out.txt", "w", stdout)
using namespace std;
 
typedef long long LL;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const double inf = 0x3f3f3f3f3f3f;
const double PI = acos(-1.0);
const double eps = 1e-8;
const int maxn = 1e3 + 5;
const int mod = 1e9 + 7;
const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, 1, -1};
const char *de[] = {"0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"};
int n, m;
const int mon[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int monn[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
inline int Min(int a, int b){ return a < b ? a : b; }
inline int Max(int a, int b){ return a > b ? a : b; }
inline LL Min(LL a, LL b){ return a < b ? a : b; }
inline LL Max(LL a, LL b){ return a > b ? a : b; }
inline bool is_in(int r, int c){
    return r >= 0 && r < n && c >= 0 && c < m;
}
string s;
map<string, string> ans;
int a[30];
 
int main(){
    while(cin >> s){
        bool ok = false;
        memset(a, 0, sizeof a);
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == ':')  a[s[i-1]-'a'] = 2;
            else a[s[i]-'a'] = 1;
        }
 
        cin >> n;
        getchar();
        for(int kase = 1; kase <= n; ++kase){
            ans.clear();
            getline(cin, s);
            stringstream ss(s);
            bool ok = false;
            string t;
            int x = 0;
            while(ss >> s){
                if(!x){ ++x; continue; }
 
                if(s[0] != '-' && !ok)  break;
                if(ok){  ans[t] = s;  ok = false; }
                else if(s.size() > 1 && s[0] == '-' &&  a[s[1]-'a'] == 1)  ans[s] = "A";
                else if(s.size() > 1 && s[0] == '-' &&  a[s[1]-'a'] == 2)  t = s, ok = true;
                else break;
            }
            if(!ans.size())  printf("Case %d: ", kase);
            else printf("Case %d:", kase);
            for(map<string, string> :: iterator it = ans.begin(); it != ans.end(); ++it)
                if(it->second == "A")  cout << " " << it->first;
                else cout << " " << it->first << " " << it->second;
            cout << endl;
        }
    }
    return 0;
}

