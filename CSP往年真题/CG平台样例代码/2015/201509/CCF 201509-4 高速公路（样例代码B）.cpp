#include<bits/stdc++.h>
#define Fox ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
using namespace std;
const int N=1e4+10;
const int M=1e5+10;
int n,m,ans=0;
int num,top,cnt;
int dfn[N],low[N],st[N],ins[N],c[N];
int head[N],nxt[M],ver[M],tot;
vector<int>scc[N];
void add(int x,int y){
	ver[++tot]=y;nxt[tot]=head[x];
	head[x]=tot;
}
void tarjan(int x){
	dfn[x]=low[x]=++num;
	st[++top]=x,ins[x]=1;
	for(int i=head[x];i;i=nxt[i]){
		if(!dfn[ver[i]]){
			tarjan(ver[i]);
			low[x]=min(low[x],low[ver[i]]);
		}
		else if(ins[ver[i]])low[x]=min(low[x],dfn[ver[i]]);
		
	}
	if(dfn[x]==low[x]){
		int y;cnt++;
		do{
			y=st[top--],ins[y]=0;
			c[y]=cnt,scc[cnt].push_back(y);
		}while(x!=y);
	}
}
int main(){
	Fox;
	cin>>n>>m;
	for(int i=1,x,y;i<=m;i++){
		cin>>x>>y;
		add(x,y);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])tarjan(i);
	for(int i=1;i<=cnt;i++){
		int sz=(int)scc[i].size();
		ans+=sz*(sz-1)/2;
	}
	cout<<ans;
    return 0;
}

