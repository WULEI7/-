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
    cin >> _;
    while (_--)
    {
        cin >> n;
        int ans1 = 1, ans2 = 1;

        int odd = n / 3;
        for (;; odd++)
            if ((odd & 1) && (odd * 3 + 1 > n))
                break;
        ans1 += (n-odd)/2;

        int m = n+1;
        if(m&1) m++;
        m = m/2;
        ans2 += (n-m); 

        cout << ans1 + ans2 << endl;
    }

    return 0;
}
