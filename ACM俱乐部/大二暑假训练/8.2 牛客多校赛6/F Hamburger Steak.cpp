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
const int mod = 1e9 + 7;
using namespace std;

int n, m;
int t[N];

signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int _ = 1;
    // cin >> _;
    while (_--)
    {
        cin >> n >> m;
        int i;
        int sum = 0;
        int ma = 0;
        forab(i, 1, n) cin >> t[i], sum += t[i], ma = max(ma, t[i]);
        // sort(t + 1, t + 1 + n);
        ma = max((sum + m - 1) / m, ma);
        int now = 1; // 第几个锅
        int s = 0;   // 使用时间
        forab(i, 1, n)
        {
            if (t[i] + s <= ma)
            {
                printf("1 %lld %lld %lld\n", now, s, s + t[i]);
                s += t[i];
                if (s == ma)
                {
                    s = 0;
                    now++;
                }
            }
            else
            {
                int l1 = s, r1 = ma; // 上一个锅
                now++;
                int l2 = 0, r2 = t[i] - (ma - s); //当前锅
                printf("2 %lld %lld %lld %lld %lld %lld\n", now, l2, r2, now - 1, l1, r1);
                s = r2;
            }
        }
    }
    return 0;
}
