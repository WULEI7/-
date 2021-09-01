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

signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int _ = 1;
    // cin >> _;
    while (_--)
    {
        cin >> n;
        string ans = "";
        vi dig;
        int now, pre, add;
        now = pre = 3;
        add = 1;
        dig.eb(add);
        if (n == 1)
            cout << 2 << endl;
        else if (n == 2)
            cout << 3 << endl;
        else if (n == 3)
            cout << 6 << endl;
        else
        {
            while (n > now)
            {
                pre = now;
                add *= 3;
                dig.eb(add);
                now += add * 3;
            }

            int x = dig[sz(dig) - 1];
            if (pre < n && n <= pre + x)
                ans += '2', n -= pre;
            else if (pre + x < n && n <= pre + 2 * x)
                ans += '3', n -= (pre + x);
            else if (pre + 2 * x < n && n <= pre + 3 * x)
                ans += '6', n -= (pre + 2 * x);

            for (int i = sz(dig) - 2; i >= 1; i--)
            {
                int x = dig[i];
                if (n <= x)
                    ans += '2';
                else if (x < n && n <= 2 * x)
                    ans += '3', n -= x;
                else if (2 * x < n && n <= 3 * x)
                    ans += '6', n -= 2 * x;
            }
            
            if (n == 1)
                ans += '2';
            else if (n == 2)
                ans += '3';
            else if (n == 3)
                ans += '6';
            cout << ans << endl;
        }
    }

    return 0;
}
