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
#define int_ int
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

int_ n, m;
string s;

signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int _ = 1;
    cin >> _;
    while (_--)
    {
        cin >> n;
        cin >> s;
        map<pair<int, int>, int> a;
        a[make_pair(0,0)] = 1;
        int ans = 0;
        int_ x = 0, y = 0;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == 'U') y++;
            else if(s[i] == 'D') y--;
            else if(s[i] == 'L') x--;
            else if(s[i] == 'R') x++;
            pair<int, int> p = make_pair(x,y);
            a[p]++;
            if(a[p] > 1) ans += (a[p]-1);
        }
        cout << ans << endl;
    }

    return 0;
}
