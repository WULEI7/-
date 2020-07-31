#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define mem(x,y) memset(x,y,sizeof(x))
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mp make_pair
#define pb push_back
#define db double
#define inf 0x3f3f3f3f
bool ispow(ll n){return (n&(n-1))==0;}
#define lowbit(x) (x&(-x))
const int mod=1e9+7;
char a[105][105];
bool vis[105][105];
int dx[4]={0,0,-1,1},dy[4]={1,-1,0,0};
int n,m,q;
bool check(int x,int y){
	if(x<0||y<0||x>=m||y>=n) return false;
	if(vis[y][x]) return false;
	if(a[y][x]=='+'||a[y][x]=='|'||a[y][x]=='-') return false;
	return true;
}

void dfs(int x,int y,char c){
	if(vis[y][x]) return;
	a[y][x]=c;
	vis[y][x]=true;
	for(int i=0;i<4;i++){
		int nx=x+dx[i],ny=y+dy[i];
		if(check(nx,ny)) dfs(nx,ny,c);
	}
}

int main()
{
	fast;
	cin>>m>>n>>q;
	for(int i=0;i<=102;i++){
		for(int j=0;j<=102;j++) a[i][j]='.';
	}
	while(q--){
		int op;
		cin>>op;
		if(op==0){
			int x1,x2,y1,y2;
			cin>>x1>>y1>>x2>>y2;
			y1=n-1-y1;
			y2=n-1-y2;
			if(x1==x2){
				if(y1>y2) swap(y1,y2);
				for(int i=y1;i<=y2;i++){
					if(a[i][x1]=='-'||a[i][x1]=='+') a[i][x1]='+';
					else a[i][x1]='|';
				}
			}
			else{
				if(x1>x2) swap(x1,x2);
				for(int i=x1;i<=x2;i++){
					if(a[y1][i]=='|'||a[y1][i]=='+') a[y1][i]='+';
					else a[y1][i]='-';
				}
			}
		}
		else {
			int x,y;
			char c;
			cin>>x>>y>>c;
			y=n-1-y;
			mem(vis,0);
			dfs(x,y,c);
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<a[i][j];
		}
		cout<<'\n';
	}
	return 0;
}

