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
const int N = 2e5 + 100;
const int mod = 1e9 + 7;
using namespace std;

int n, m;
string s1 = "1";
string s2 = "0001";
string s3 = "01";
string s4 = "1001";

signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int _ = 1;
    cin >> _;
    while (_--)
    {
        cin >> n;
        if (n <= 4)
        {
            if (n == 1)
                cout << 1 << '\n'
                     << s1 << '\n';
            else if (n == 2)
                cout << 4 << '\n'
                     << s2 << '\n';
            else if (n == 3)
                cout << 2 << '\n'
                     << s3 << '\n';
            else if (n == 4)
                cout << 4 << '\n'
                     << s4 << '\n';
        }
        else
        {
            m = 0;
            int x = n / 4;
            m += x * 4;
            int y = n % 4;
            string ans = "";
            if (y == 1)
                ans += s1, m += 1;
            else if (y == 2)
                ans += s2, m += 4;
            else if (y == 3)
                ans += s3, m += 2;
            for (int i = 0; i < x; i++)
                ans += s4;
            cout << m << '\n'
                 << ans << '\n';
        }
    }

    return 0;
}
