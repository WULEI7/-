#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fast ios::sync_with_stdio(false)
#define all(x) (x).begin(), (x).end()
#define mset(a, n) memset(a, n, sizeof(a))
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define forab(i, a, b) for (int i = (a); i <= (b); ++i)
#define forba(i, b, a) for (int i = (b); i >= (a); --i)
#define db double
#define ll long long
#define inf 0x3f3f3f3f
#define endl '\n'
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define de(x) cout  << #x << " = " << x << ' '
#define dee(x) cout  << #x << " = " << x << endl

using namespace std;

typedef pair<int, int> pii;

inline int lowbit(int x) { return x & (-x); }

template<typename T>
inline void read(T &x) {
    x = 0;
    T fg = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-')
            fg = -1;
        ch = getchar();
    }
    while (isdigit(ch))
        x = x * 10 + ch - '0', ch = getchar();
    x = fg * x;
}

template<typename T, typename... Args>
inline void read(T &x, Args &... args) { read(x), read(args...); }

const ll MOD = 1e9 + 7;
const ll mod = 998244353;
const int N = 50;
const int maxn = 5e4 + 5;

string pos, s;
int t;

int main() {
    fast;
    // freopen("10.in", "r", stdin);
    // freopen("10.out", "w", stdout);
    cin >> t;
    cin >> pos;
    cin.ignore();
    while (t--) {
        getline(cin, s);
        if (s.empty()) {
            s = pos;
            cout << pos << "\n";
            continue;
        }
        if (s[0] != '/') {
            s = pos + '/' + s;
        }
        stack<string> st;
        bool flag = true;
        string t = "";
        int len = SZ(s);
        forab(j, 1, len) {
            if (s[j] == '/' || j == len) {
                if (!flag) {
                    flag = true;
                    if (t == ".") {
                        t.clear();
                        continue;
                    } else if (t == "..") {
                        if (st.empty()) {
                            t.clear();
                            continue;
                        } else {
                            t.clear();
                            st.pop();
                        }
                    } else {
                        st.push(t);
                        t.clear();
                    }
                } else {
                    continue;
                }
            } else {
                flag = false;
                t = t + s[j];
            }
        }
        vector<string> v;
        while (!st.empty()) {
            v.pb(st.top());
            st.pop();
        }
        if (!SZ(v)) {
            cout << "/\n";
        } else {
            forba(i, SZ(v) - 1, 0) {
                cout << "/" << v[i];
            }
            cout << "\n";
        }
    }
}

