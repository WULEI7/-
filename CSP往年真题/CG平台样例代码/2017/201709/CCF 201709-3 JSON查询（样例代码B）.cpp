#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<iostream>
#include<sstream>
#include<iterator>
#include<algorithm>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include<deque>
#include<queue>
#include<list>
#define lowbit(x) (x & (-x))
const double eps = 1e-8;
inline int dcmp(double a, double b){
    if(fabs(a - b) < eps) return 0;
    return a > b ? 1 : -1;
}
typedef long long LL;
typedef unsigned long long ULL;
const int INT_INF = 0x3f3f3f3f;
const int INT_M_INF = 0x7f7f7f7f;
const LL LL_INF = 0x3f3f3f3f3f3f3f3f;
const LL LL_M_INF = 0x7f7f7f7f7f7f7f7f;
const int dr[] = {0, 0, -1, 1, -1, -1, 1, 1};
const int dc[] = {-1, 1, 0, 0, -1, 1, -1, 1};
const int MOD = 1e9 + 7;
const double pi = acos(-1.0);
const int MAXN = 8000 + 10;
const int MAXT = 10000 + 10;
using namespace std;
map<string, int> mp[MAXN];
map<int, int> ma[MAXN];
map<int, string> ans[MAXN];
int len;
string s;
int k;
vector<string> tmp;
bool vis[MAXN];
void solve(int fa, int &pos, int num);
void deal(int &i, int num, int cnt)
{
    int len = s.size();
    int j, et, st;
    string x;
    for(j = i - 1; j >= 0; --j)
	{
        if(s[j] == '\"')
		{
            et = j;
            break;
        }
    }
    for(j = et - 1; j >= 0; --j)
	{
        if(s[j] == ',' || s[j] == '{')
		{
            break;
        }
        x += s[j];
    }
//    cout << x << endl;
//    cout << "***********" << endl;
    x.resize(x.size() - 1);
    reverse(x.begin(), x.end());
//    cout << x << endl;
//    cout << "**************" << endl;
    mp[num][x] = cnt;
    int id = mp[num][x];
    j = i + 1;
    if(s[j] == '\"')
	{
        st = j;
        x = "";
        for(j = st + 1; j < len; ++j)
		{
            if(s[j] == ',' || s[j] == '}') break;
            x += s[j];
        }
        x.resize(x.size() - 1);
        ans[num][id] = "STRING " + x;
    }
    else if(s[j] == '{')
	{
        ans[num][id] = "OBJECT";
        ma[num][id] = ++k;
        solve(id, j, k);
    }
    i = j;
}
void solve(int fa, int &pos, int num)
{
    int cnt = 0;
    for(int i = pos + 1; i < len; ++i)
	{
        if(s[i] == ':')
		{
            ++cnt;
            deal(i, num, cnt);
            if(s[i] == '}')
			{
                pos = ++i;
                break;
            }
        }
    }
}
bool Find(int cur, int num, int l, string& res, int id)
{
    if(num == l)
	{
        res = ans[cur][id];
        return true;
    }
    else
	{
        cur = ma[cur][id];
        if(!mp[cur].count(tmp[num])) return false;
        return Find(cur, num + 1, l, res, mp[cur][tmp[num]]);
    }
}
int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    getchar();
    while(n--)
	{
        string str;
        getline(cin, str);
        int l = str.size();
        for(int i = 0; i < l; ++i)
		{
            if(str[i] == ' ') 
			    continue;
            if(str[i] == '\\')
			{
                s += str[i + 1];
                ++i;
                continue;
            }
            s += str[i];
        }
    }
//    cout << s << endl;
//    cout << "************" << endl;
    len = s.size();
    for(int i = 0; i < len; ++i)
	{
        if(s[i] == '{')
		{
            ++k;
            vis[k] = true;
            solve(-1, i, k);
        }
    }
    string x;
    while(m--)
	{
        cin >> x;
        int l = x.size();
        tmp.clear();
        int id = 0;
        for(int i = 0; i < l; ++i)
		{
            if(x[i] == '.')
			{
                tmp.push_back(x.substr(id, i - id));
                id = i + 1;
            }
        }
        tmp.push_back(x.substr(id, l - id));
        l = tmp.size();
        string res;
        bool ok = false;
        for(int i = 1; i <= k; ++i){
            if(!vis[i]) continue;
            if(mp[i].count(tmp[0])){
                int id = mp[i][tmp[0]];
                if(Find(i, 1, l, res, id)){
                    ok = true;
                    printf("%s\n", res.c_str());
                    break;
                }
            }
        }
        if(!ok){
            printf("NOTEXIST\n");
        }
    }
    return 0;
}

