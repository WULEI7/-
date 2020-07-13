#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
#define dbg(x...) do { cout << "\033[32;1m" << #x <<" -> "; err(x); } while (0)
void err() { cout << "\033[39;0m" << endl; }
template<class T, class... Ts> void err(const T& arg,const Ts&... args) { cout << arg << " "; err(args...); }
typedef unsigned long long ull;
const int N = 1000010;
ull U[5] = {
    314882150829468584,
    427197303358170108,
    1022292690726729920,
    1698479428772363217,
    2006101093849356424
};
ull mod = 2009731336725594113;
unordered_map<ull, int> mp;
ull f[35],a[N][35];
int g[35][35];
ull mul(ull a, ull b){
    ull res = 0;
    for(;b;b>>=1){
        if(b & 1) res = (res + a) % mod;
        a = (a + a) % mod;
    }
    return res;
}
void getConvert(){
    queue<ull> q;
    int id = 1;
    for(int i=0;i<5;i++)q.push(U[i]), mp[U[i]] = id++;
    while(q.size()){
        ull x = q.front();q.pop();
        f[mp[x]] = x;
        for(int i=0;i<5;i++){
            ull t = mul(x, U[i]);
            if(mp[t]) {
                continue;   
            }
            mp[t] = id++;
            q.push(t);
        }
    }
    for(int i=1;i<=32;i++){
        for(int j=i;j<=32;j++){
            g[i][j] = g[j][i] = mp[mul(f[i], f[j])];
        }
    }
}
int tmp[33];
int n, q;
struct SegTree{
    int l,r;
    int s[33];//维护它，但是它后期可能还会变
    int res;
    int tag;
    // 转移函数，target表示乘 f[target]
    void convert(int target){
        for(int i=1;i<=32;i++){
            tmp[i] = s[g[i][target]];
        }
        for(int i=1;i<=32;i++){
            s[i] = tmp[i];
        }
        res = s[28];
        if(tag == 0) tag = target;
        else tag = g[tag][target];
    }
}t[N<<2];
/*
    下面初始res取 s[28]的原因是32个数字中第28个是 1
*/
void build(int p, int l, int r){
    t[p].l = l;t[p].r = r;
    if(l == r){
        for(int i=1;i<=32;i++){
            t[p].s[i] = a[l][i] % 2019;
        }
        t[p].res = t[p].s[28];
        t[p].tag = 0;
        return;
    }
    int mid = l + r >> 1;
    build(p*2, l, mid);
    build(p*2+1, mid+1, r);
    for(int i=1;i<=32;i++){
        t[p].s[i] = t[p*2].s[i] + t[p*2+1].s[i];
    }
    t[p].res = t[p].s[28];
    t[p].tag = 0;
}
void pushdown(int p){
    if(t[p].tag){
        t[2*p].convert(t[p].tag);
        t[2*p+1].convert(t[p].tag);
        t[p].tag = 0;
    }
}
int ask(int p, int l, int r){
    if(t[p].l >= l && t[p].r <= r){
        return t[p].res;
    }
    pushdown(p);
    int mid = t[p].l + t[p].r >> 1;
    int res = 0;
    if(mid >= l) res = ask(p*2, l, r);
    if(mid < r) res = res + ask(p*2+1, l, r);
    return res;
}
void change(int p, int l, int r, int k){
    if(t[p].l >= l && t[p].r <= r){
        t[p].convert(k+1);
        return;
    }
    pushdown(p);
    int mid = t[p].l + t[p].r >> 1;
    if(mid >= l) change(p*2, l, r, k);
    if(mid < r) change(p*2+1, l, r, k);
    for(int i=1;i<=32;i++) t[p].s[i] = t[p*2].s[i] + t[p*2+1].s[i];
    t[p].res = t[p].s[28];
}
int main(){
    getConvert();
    scanf("%d%d", &n, &q);
    // 由于序列是1...n，所以可以直接用加法递推
    for(int i=1;i<=n;i++){
        for(int j=1;j<=32;j++){
            if(i == 1) a[i][j] = f[j] % mod;
            else a[i][j] = (f[j] + a[i-1][j]) % mod;
        }
    }
    build(1, 1, n);
    while(q--){
        int l, r;
        scanf("%d%d", &l, &r);
        int res = ask(1, l, r);
        printf("%d\n", res);
        change(1, l, r, res % 5);
    }
    return 0;
}
