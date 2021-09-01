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

namespace GenHelper
{
    unsigned z1, z2, z3, z4, b, u;
    unsigned get()
    {
        b = ((z1 << 6) ^ z1) >> 13;
        z1 = ((z1 & 4294967294U) << 18) ^ b;
        b = ((z2 << 2) ^ z2) >> 27;
        z2 = ((z2 & 4294967288U) << 2) ^ b;
        b = ((z3 << 13) ^ z3) >> 21;
        z3 = ((z3 & 4294967280U) << 7) ^ b;
        b = ((z4 << 3) ^ z4) >> 12;
        z4 = ((z4 & 4294967168U) << 13) ^ b;
        return (z1 ^ z2 ^ z3 ^ z4);
    }
    bool read()
    {
        while (!u)
            u = get();
        bool res = u & 1;
        u >>= 1;
        return res;
    }
    void srand(int x)
    {
        z1 = x;
        z2 = (~x) ^ 0x233333333U;
        z3 = x ^ 0x1234598766U;
        z4 = (~x) + 51;
        u = 0;
    }
}
using namespace GenHelper;
// bool edge[8005][8005];
vector<bool> v[8005];

signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int _ = 1;
    // cin >> _;
    while (_--)
    {
        // cin >> n >> m;

        int n, seed;
        cin >> n >> seed;
        srand(seed);
        for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= n; j++)
            {
                bool xxx = read();
                if (xxx == false)
                {
                    v[i].emplace_back(xxx);
                    v[j].emplace_back(xxx);
                }
            }

        long long sum = 0;
        for (int i = 1; i <= n; i++)
            sum += (v[i].size() * (n - v[i].size() - 1));

        cout << (long long)n * (n - 1) * (n - 2) / 6 - sum / 2 << endl;
    }

    return 0;
}
