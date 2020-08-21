#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define retunr return
#define pb push_back
#define mp make_pair
#define null NULL
//#define sc(x) scanf("%d", &x)
#define sc64(x) scanf("%lld", &x)
//#define pr(x) printf("%d", (x))
#define pr64(x) printf("%lld", (x))
#define sp putchar(' ')
#define ln putchar('\n')
#define rep(i,l,r) for (register int i = l, lim = r;i <= lim; ++i)
#define repr(i,l,r) for (register int i = r, lim = l;i >= lim; --i)
#define fi first
#define se second
#define SET(__set, val) memset(__set, val, sizeof __set)
#define fill(a,v,n) memset((a),(v),sizeof(a[0])*(n))
#define copy(a,b,n) memcpy((a),(b),sizeof(a[0])*(n))
#define ALL(x) (x.begin(),x.end())
#define prf(x) printf("%.20f", x)
#define for_each_edge(u) for(int i = point[u];i;i=G[i].n)
typedef unsigned int uint;
typedef double db;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
#define N 100010
#define M 18
#define MOD 1000000007
#define _add(a,b) {(a)+=(b);if((a)>=MOD)(a)-=MOD;}
//inline void _add(int &a, int b){a+=b;if(a>=MOD)a-=MOD;}
#define _sub(a,b) {(a)-=(b);if((a)<0)(a)+=MOD;}
//inline void _sub(int &a, int b){a-=b;if(a<0)a+=MOD;}
#define _mul(a,b) {(a)=(ll)a*(b)%MOD;}
//inline void _mul(int &a, int b){a = (ll)a*b%MOD;}
inline void _max(int &a, int b){if(b>a)a=b;}
inline void _min(int &a, int b){if(b<a)a=b;}
#define BUF_SIZE 100000
bool IOerror = 0;
inline char nc(){//next char
	static char buf[BUF_SIZE], *p1 = buf + BUF_SIZE, *pend = buf + BUF_SIZE;
	if(p1 == pend){
		p1 = buf;
		pend = buf + fread(buf, 1, BUF_SIZE, stdin);
		if(pend == p1){
			IOerror = 1;
			return -1;
		}
	}
	return *p1++;
}
inline bool blank(char ch){
	return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
}
inline int sc(int &x){
	char ch;
	int sgn = 1;
	while(blank(ch = nc()));
	if(IOerror)
		return -1;
	if(ch=='-')sgn=-1,ch=nc();
	for(x = ch - '0'; (ch = nc()) >= '0' && ch <= '9'; x = x * 10 + ch - '0');
	x*=sgn;
	return 1;
}
inline void pr(int x){
	if (x == 0){
		putchar('0');
		return;
	}
	short i, d[19];
	for (i = 0;x; ++i)
		d[i] = x % 10, x /= 10;
	while (i--)
		putchar(d[i] + '0');
}
const int infi = 2147483647;
const ll infl = 9223372036854775807ll;
const db PI = 3.14159265358979323846;
 
struct E{
	int v, n;
}G[N*2];
int cnt, point[N];
inline void adde(int u, int v){
	G[++cnt]=(E){v,point[u]},point[u]=cnt;
	G[++cnt]=(E){u,point[v]},point[v]=cnt;
}
int siz[N], maxs[N], r, num;
bool vis[N], hh[N];
int dep[N];
int n, m;
inline void Ginit(){
	cnt = 0;
	fill(point,0,n+1);
}
int path[N];
int D, flag;
int bfslist[N];
int bfsfa[N];
int bfslength;
int queue[N];
int hd, tl;
inline void grbfs(int s){
	siz[r=0] = N;
	bfslength = 0;
	hd = 0, tl = 1;
	queue[hd] = s;
	bfsfa[s] = 0;
	while(hd<tl){
		int u = queue[hd++];
		bfslist[++bfslength] = u;
		siz[u] = 1;
		maxs[u] = 0;
		for_each_edge(u){
			int v = G[i].v;
			if(vis[v] || v==bfsfa[u])continue;
			bfsfa[v] = u;
			queue[tl++] = v;
		}
	}
	repr(i,1,bfslength){
		int u = bfslist[i];
		if(bfsfa[u]){
			siz[bfsfa[u]]+=siz[u];
			_max(maxs[bfsfa[u]],siz[u]);
		}
		_max(maxs[u], num-siz[u]);
		if(maxs[r]>maxs[u])
			r = u;
	}
}
int tr[N];
inline void upd(int d, int x, int nn){
	for(;d <= nn;d += d&-d)tr[d] += x;
}
inline int ask(int d){
	int res(0);
	for(;d > 0;d -= d&-d)res += tr[d];
	return res;
}
int tmp[N];
int maxdep;
int c[N];
int tmplist[N];
int length;
int Maxdep;
int son[N];
int sons;
inline void bfs(int s){
	hd = 0, tl = 1;
	queue[hd] = s;
    hh[s] = 1;
    while(hd<tl){
    	int u = queue[hd++];
	    for_each_edge(u){
	    	int v = G[i].v;
            if (hh[v] || vis[v])continue;
            if(dep[v] > maxdep){
            	maxdep = dep[v];
            	c[maxdep] = 0;
            }
            c[dep[v]]++;
            hh[v] = 1;
            if(dep[v]<=D){
	            if(flag)_add(tmp[v], ask(min(Maxdep,D+1-dep[v])))
	            else	_sub(tmp[v], ask(min(Maxdep,D+1-dep[v])))
				queue[tl++] = v;
            }
        }
    }
}
int tmpfa[N];
inline void buildlist(int s){
	hd = 0, tl = 1;
	queue[hd] = s;
	tmpfa[s] = 0;
	while(hd<tl){
		int u = queue[hd++];
		tmplist[++length] = u;
		_max(Maxdep,dep[u]);
		for_each_edge(u){
		   	int v = G[i].v;
	        if (vis[v] || v==tmpfa[u])continue;
	        tmpfa[v] = u;
			dep[v]=dep[u]+1;
			queue[tl++] = v;
	    }
	}
}
inline void solve(int u){
	length = 0;
	Maxdep = 0;
    dep[u] = 1, vis[u] = 1;
	buildlist(u);
    sons = 0;
    for_each_edge(u)if(!vis[G[i].v])son[++sons] = G[i].v;
    rep(i,1,length)tmp[tmplist[i]] = 0;
    rep(i,1,Maxdep)tr[i] = 0;
	rep(i,1,length)hh[tmplist[i]] = 0;
	rep(i,1,sons){
		int v = son[i];
        c[2] = 1;
        if(dep[v]<=D){
            if(flag)_add(tmp[v], ask(min(Maxdep,D+1-dep[v])))
            else	_sub(tmp[v], ask(min(Maxdep,D+1-dep[v])))
        }
        maxdep = 2;
    	bfs(v);
    	rep(j,2,maxdep)upd(j,c[j],Maxdep);
    }
	repr(i,1,length){
		int v = tmplist[i];
		_add(tmp[tmpfa[v]],tmp[v]);
		_add(path[v],tmp[v]);
	}
	_sub(path[u],tmp[u]);
    rep(i,1,length)tmp[tmplist[i]] = 0;
    rep(i,1,Maxdep)tr[i] = 0;
	rep(i,1,length)hh[tmplist[i]] = 0;
	repr(i,1,sons){
		int v = son[i];
    	dep[v] = 2;
        c[2] = 1;
        if(dep[v]<=D){
            if(flag)_add(tmp[v], ask(min(Maxdep,D+1-dep[v])))
            else	_sub(tmp[v], ask(min(Maxdep,D+1-dep[v])))
        }
        maxdep = 2;
    	bfs(v);
    	rep(j,2,maxdep)upd(j,c[j],Maxdep);
    }
	repr(i,1,length){
		int v = tmplist[i];
		_add(tmp[tmpfa[v]],tmp[v]);
		_add(path[v],tmp[v]);
	}
    rep(i,1,length)tmp[tmplist[i]] = 0;
	repr(i,1,length){
		int v = tmplist[i];
		if(v != u && dep[v]<=D){
        	if(flag)_add(tmp[v],1)
	        else	_sub(tmp[v],1)
			_add(tmp[tmpfa[v]],tmp[v]);
	    }
		_add(path[v],tmp[v]);
	}
    rep(i,1,length)tmp[tmplist[i]] = 0;
    rep(i,1,length)hh[tmplist[i]] = 0;
    for_each_edge(u){
    	int v = G[i].v;
        if (vis[v])continue;
        num = siz[v];
		grbfs(v);
        solve(r);
    }
}
inline void p_d(){
	fill(vis,0,n+1);
	maxs[r=0]=N;
	num = n;
    grbfs(1);
    solve(r);
}
int s[N][M], fa[N][M];
inline int sum(int u, int v){
	if(dep[u] < dep[v])swap(u,v);
	int res(path[u]);
	repr(i,0,M-1)if(((dep[u]-dep[v])>>i)&1){
		_add(res, s[u][i]); u = fa[u][i];
	}
	if(u == v)return res;
	_add(res, path[v]);
	repr(i,0,M-1)if(fa[u][i] != fa[v][i]){
		_add(res, s[u][i]); _add(res, s[v][i]); u = fa[u][i], v = fa[v][i];
	}
	_add(res,path[fa[u][0]]);
	return res;
}
inline void finalbfs(int rt){
	hd = 0, tl = 1;
	queue[hd] = rt;
	dep[rt] = 0;
    while(hd<tl){
    	int u = queue[hd++];
		for_each_edge(u){
			int v = G[i].v;
			if(v!=fa[u][0]){
				fa[v][0] = u;
				s[v][0] = path[u];
				dep[v] = dep[u]+1;
	  	  		queue[tl++] = v;
			}
		}
	}
}
int a[N];
inline int len(int l, int r){
	if(l>r)return 0;
	return r-l+1;
}
inline int psum(int l, int r){
	if(l>r)return 0;
	int res = l+r;
	_mul(res,r-l+1);
	_mul(res,500000004);
	return res;
}
int main(){
	//freopen("1.txt", "r", stdin);
	//freopen("2.txt", "w", stdout);
	int Case;
	sc(Case);
	rep(ca, 1, Case){
		int l,r;
		sc(n),sc(m),sc(l),sc(r);
		int mm = 1;
		rep(i,1,n){
			sc(a[i]),path[i] = 0;
			SET(fa[i],0);
			SET(s[i],0);
		}
		Ginit();
		rep(i,2,n){
			int fa;
			sc(fa);
			adde(fa,i);
			if(fa != i-1)mm = 0;
		}
		int ans = 0;
		if(!mm){
			D = r;
			flag = 1;
			if(D>=1){
				rep(i,1,n)_add(path[i],1);
				if(D>1)
					p_d();
			}
			D = l-1;
			flag = 0;
			if(D>=1){
				rep(i,1,n)_sub(path[i],1);
				if(D>1)
					p_d();
			}
			rep(i,1,n){
				_mul(a[i],path[i]);
				_add(ans,a[i]);
			}
			finalbfs(1);
			rep(k,1,M-1)rep(i,1,n){
				fa[i][k] = fa[fa[i][k-1]][k-1];
				s[i][k] = s[i][k-1];
				_add(s[i][k],s[fa[i][k-1]][k-1]);
			}
		}else{
			// long chain
			D = r;
			rep(i,1,n){
				if(i<n-D+1){
					_add(path[i], psum(max(D-i+1,1),D));
				}else{
					_add(path[i], psum(max(D-i+1,1),n-i+1));
					int tmp = n-i+1;
					_mul(tmp,i-(n-D+1));
					_add(path[i], tmp);
				}
			}
			D = l-1;
			rep(i,1,n){
				if(i<n-D+1){
					_sub(path[i], psum(max(D-i+1,1),D));
				}else{
					_sub(path[i], psum(max(D-i+1,1),n-i+1));
					int tmp = n-i+1;
					_mul(tmp,i-(n-D+1));
					_sub(path[i], tmp);
				}
			}
			rep(i,1,n){
				_mul(a[i],path[i]);
				_add(ans,a[i]);
				_add(path[i],path[i-1]);
			}
		}
		rep(i,1,m){
			int u, v, d;
			sc(u),sc(v),sc(d);
			if(!mm){
				_mul(d,sum(u,v));
				_add(ans,d);
			}else{
				// long chain
				if(u>v)swap(u,v);
				int tmp = path[v];
				_sub(tmp,path[u-1]);
				_mul(d,tmp);
				_add(ans,d);
			}
			pr(ans),ln;
		}
	}
	return 0;
}
