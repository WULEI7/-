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
#define vt3 vector<tuple<int,int,int>>
#define mem(ara, n) memset(ara, n, sizeof(ara))
#define memb(ara) memset(ara, false, sizeof(ara))
#define all(x) (x).begin(), (x).end()
#define sq(x) ((x) * (x))
#define sz(x) x.size()
const int N = 1e5 + 100;
const int mod = 1e9 + 7;
using namespace std;
namespace often
{
    inline void input(int &res)
    {
        char c = getchar();
        res = 0;
        int f = 1;
        while (!isdigit(c))
        {
            f ^= c == '-';
            c = getchar();
        }
        while (isdigit(c))
        {
            res = (res << 3) + (res << 1) + (c ^ 48);
            c = getchar();
        }
        res = f ? res : -res;
    }
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
    int fact(int n)
    {
        int res = 1;
        for (int i = 1; i <= n; i++)
            res = res * 1ll * i % mod;
        return res;
    }
    int C(int n, int k)
    {
        return fact(n) * 1ll * qpow(fact(k), mod - 2) % mod * 1ll * qpow(fact(n - k), mod - 2) % mod;
    }
    int exgcd(int a, int b, int &x, int &y)
    {
        if (b == 0)
        {
            x = 1, y = 0;
            return a;
        }
        int res = exgcd(b, a % b, x, y);
        int t = y;
       y = x - (a / b) * y;
        x = t;
        return res;
    }
    int invmod(int a, int mod)
    {
        int x, y;
        exgcd(a, mod, x, y);
        x %= mod;
        if (x < 0)
            x += mod;
        return x;
    }
}
using namespace often;
 
int n, m; 
double c;
vector<double> a;
 
signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int _ = 1;
    // cin >> _;
    while (_--)
    {
        cin >> n >> c;
        int i;
        forab(i,1,n)
        {
            double x;
            cin >> x;
            a.eb(x);
        }
        sort(all(a));
        partial_sum(all(a),a.begin());
        long long sum = qpow(2,n);
        double start = 0.5;
        forba(i,0,n-2)
        {
            double now = start*a[i];
            start /= 2;
            c += now;
            if(now < 1e-10)
                break;
        }
        printf("%.6lf\n", min(c,a[n-1]));
    }
    return 0;
}
