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

int trans(string s) {
    int ans = 0;
    forn(i, SZ(s)) {
        ans = ans * 10 + (int)(s[i] - '0');
    }
    return ans;
}

int p, r, u, q;

int main() {
    fast;
    cin >> p;
    map<string, int> mpp;
    while (p--) {
        string s;
        cin >> s;
        int pos = s.find(":");
        if (pos != string::npos) {
            string x = s.substr(0, pos);
            int num = trans(s.substr(pos + 1));
            mpp[x] = num;
        } else {
            mpp[s] = -1;
        }
    }
    map<string, vector<pair<string, int> > > mpr;
    cin >> r;
    while (r--) {
        string role;
        int num;
        cin >> role >> num;
        while (num--) {
            string s;
            cin >> s;
            int pos = s.find(":");
            if (pos != string::npos) {
                string x = s.substr(0, pos);
                int num = trans(s.substr(pos + 1));
                mpr[role].pb(mp(x, num));
            } else {
                mpr[role].pb(mp(s, -1));
            }
        }
    }
    map<string, vector<string> > mpu;
    cin >> u;
    while (u--) {
        string user;
        int num;
        cin >> user >> num;
        while (num--) {
            string s;
            cin >> s;
            mpu[user].pb(s);
        }
    }
    cin >> q;
    while (q--) {
        string x, y;
        cin >> x >> y;
        if (mpu.find(x) == mpu.end()) {
            cout << "false\n";
        } else {
            int pos = y.find(":");
            if (pos != string::npos) {
                string o = y.substr(0, pos);
                if (mpp.find(o) == mpp.end()) {
                    cout << "false\n";
                    continue;
                }
                auto v = mpu[x];
                bool flag = false;
                int num = trans(y.substr(pos + 1));
                for (auto k : v) {
                    for (auto m : mpr[k]) {
                        if (m.fi == o && m.se >= num) {
                            flag = true;
                        }
                        if (flag) {
                            break;
                        }
                    }
                    if (flag) {
                        break;
                    }
                }
                if (flag) {
                    cout << "true\n";
                } else {
                    cout << "false\n";
                }
            } else {
                if (mpp.find(y) == mpp.end()) {
                    cout << "false\n";
                } else if (mpp[y] != -1) {
                    auto v = mpu[x];
                    bool flag = false;
                    int t = -1;
                    for (auto k : v) {
                        for (auto m : mpr[k]) {
                            if (m.fi == y && m.se >= 0) {
                                t = max(t, m.se);
                                flag = true;
                            }
                        }
                    }
                    if (flag) {
                        cout << t << "\n";
                    } else {
                        cout << "false\n";
                    }
                } else {
                    auto v = mpu[x];
                    bool flag = false;
                    for(auto k : v) {
                        for (auto m : mpr[k]) {
                            if (m.fi == y) {
                                flag = true;
                                break;
                            }
                            if (flag) {
                                break;
                            }
                        }
                        if (flag) {
                            break;
                        }
                    }
                    if (flag) {
                        cout << "true\n";
                    } else {
                        cout << "false\n";
                    }
                }
            }
        }
    }
    return 0;
}

