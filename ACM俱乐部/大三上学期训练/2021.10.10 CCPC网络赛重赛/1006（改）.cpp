#include <bits/stdc++.h>
#define pr printf
#define sc scanf
#define for0(i, n) for (i = 0; i < n; i++)
#define for1n(i, n) for (i = 1; i <= n; i++)
#define forab(i, a, b) for (i = a; i <= b; i++)
#define forba(i, a, b) for (i = b; i >= a; i--)
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define int long long
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<vector<int>>
#define vt3 vector<tuple<int, int, int>>
#define mem(ara, n) memset(ara, n, sizeof(ara))
#define memb(ara) memset(ara, false, sizeof(ara))
#define all(x) (x).begin(), (x).end()
#define sq(x) ((x) * (x))
#define sz(x) x.size()
const int N = 1e5 + 100;
const int mod = 998244353;
using namespace std;

int n, m;
string s1 = "nunhehheh";
int a[N];
int dp[10];
int dpp[N][10];

long long ans = 0;

inline int qpow(int a, int b)
{
    int ans = 1, base = a;
    while (b)
    {
        if (b & 1)
            ans = (ans * base % mod + mod) % mod;
        base = (base * base % mod + mod) % mod;
        b >>= 1;
    }
    return ans;
}

signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int _ = 1;
    // cin >> _;
    while (_--)
    {
        // cin >> n >> m;
        string s2;
        cin >> s2;
        // n = s1.length();
        m = s2.length();
        a[m] = 0;
        for (int i = m - 1; i >= 0; i--)
        {
            a[i] = a[i + 1] + (s2[i] == 'a');
        }
        // cout << a[0] << endl;
        int pre = 0;
        for (int i = 0; i < m; ++i)
        {
            dpp[i][1] = (dpp[i-1][1] + (s2[i] == 'n')) % mod;
            dpp[i][2] = (dpp[i-1][2] + (s2[i] == 'u') * dpp[i - 1][1]) % mod;
            dpp[i][3] = (dpp[i-1][3] + (s2[i] == 'n') * dpp[i - 1][2]) % mod;
            dpp[i][4] = (dpp[i-1][4] + (s2[i] == 'h') * dpp[i - 1][3]) % mod;
            dpp[i][5] = (dpp[i-1][5] + (s2[i] == 'e') * dpp[i - 1][4]) % mod;
            dpp[i][6] = (dpp[i-1][6] + (s2[i] == 'h') * dpp[i - 1][5]) % mod;
            dpp[i][7] = (dpp[i-1][7] + (s2[i] == 'h') * dpp[i - 1][6]) % mod;
            dpp[i][8] = (dpp[i-1][8] + (s2[i] == 'e') * dpp[i - 1][7]) % mod;
            dpp[i][9] = (dpp[i-1][9] + (s2[i] == 'h') * dpp[i - 1][8]) % mod;
            ans += (dpp[i][9] - dpp[i-1][9]) * qpow(2, a[i + 1]) % mod;
            // cout << i << " " << dpp[i][9] << "  " << dpp[i-1][9] << endl;
        }
        // cout << dpp[m - 1][9] << "  ";
        cout << ans << endl;

    }

    return 0;
}
