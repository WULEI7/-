#include <bits/stdc++.h>
const long long mod = 4933;
using namespace std;

long long exgcd(long long a, long long b, long long &x, long long &y)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    long long res = exgcd(b, a % b, x, y);
    long long t = y;
    y = x - (a / b) * y;
    x = t;
    return res;
}
long long invmod(long long a, long long mod)
{
    long long x, y;
    exgcd(a, mod, x, y);
    x %= mod;
    if (x < 0)
        x += mod;
    return x;
}

inline long long qpow(long long a, long long b)
{
    long long ans = 1, base = a;
    while (b)
    {
        if (b & 1)
            ans = (ans * base % mod + mod) % mod;
        base = (base * base % mod + mod) % mod;
        b >>= 1;
    }
    return ans;
}
long long n, m, k, a, l;

signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int _ = 1;
    // cin >> _;
    while (_--)
    {
        cin >> n >> m >> k >> a >> l;
        long long yy = 1, zz = 1;
        for (long long i = 1; i <= k; i++)
        {
            long long x, y, z;
            cin >> x >> y >> z;
            if (x != 0)
            {
                yy = yy * (z - y) % mod;
                zz = zz * z % mod;
            }
        }
        // cout << yy << " / " << zz << endl;
        long long toilet = yy * qpow(zz, mod - 2) % mod;
        toilet += a;
        cout << toilet % mod << endl;
    }

    return 0;
}
