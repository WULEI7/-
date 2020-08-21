#include<cstdio>
#include<set>
#include<vector>
#include<map>
#include<iostream>
#include<unordered_map>
#define ll long long
//#define IO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const ll cst = 1e9;
struct commodity
{
    ll id, score;
    bool operator < (const commodity& c) const { return score != c.score ? score > c.score:id < c.id; }
};
set<commodity>goods;
unordered_map<ll, set<commodity>::iterator> mp;
int main()
{
    //IO;
    int m, n; cin >> m >> n;
    vector<int>K(m);
    for (int i = 0; i < n; i++)
    {
        int id, score; cin >> id >> score;
        for (int j = 0; j < m; j++)
        {
            ll pos = j * cst + id; commodity tmp; tmp.id = pos; tmp.score = score;
            mp[pos] = goods.insert(tmp).first;
        }
    }
    int t; cin >> t;
    while (t--)
    {
        int op; cin >> op;
        if (op == 1)
        {
            int type, id, score; cin >> type >> id >> score;
            ll pos = type * cst + id; commodity tmp; tmp.id = pos; tmp.score = score;
            mp[pos] = goods.insert(tmp).first;
        }
        else if (op == 2)
        {
            int type, id; cin >> type >> id;
            ll pos = type * cst + id;
            goods.erase(mp[pos]); mp.erase(pos);
        }
        else
        {
            int k; cin >> k;
            for (int i = 0; i < m; i++)cin >> K[i];
            vector< vector<int> >ans(m);
            for (auto& i : goods)
            {
                ll pos = i.id / cst;
                if (ans[pos].size() < K[pos])
                {
                    ans[pos].push_back(i.id % cst);
                    if (--k == 0)break;
                }
            }
            for (auto& i : ans)
                if (i.empty())cout << "-1\n";
                else
                {
                    for (auto j : i)cout << j << " ";
                    cout << "\n";
                }
        }
    }
    return 0;
}
