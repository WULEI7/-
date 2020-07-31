#include<bits/stdc++.h>
#pragma GCC optimize(3,"Ofast","inline")
#define turn_on_clock clock_t start,end;start=clock();
#define Fox ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define turn_off_clock end=clock();printf("\nTime eclipse:%.5lfms\n",(double)(end-start)/CLOCKS_PER_SEC*1000);
using namespace std;
const int M=1e6+5;
unsigned long long U[]={314882150829468584,427197303358170108,1022292690726729920,1698479428772363217,2006101093849356424};
unsigned long long mod=2009731336725594113;
unsigned long long f[35],a[M][35];
queue<unsigned long long>que;
map<unsigned long long,int>mp;
int n,q,tot,g[35][35];
unsigned long long mul(unsigned long long a,unsigned long long b){
	unsigned long long res=0;
	while(b){
		if(b&1)res=(res+a)%mod;
		a=(a+a)%mod;
		b>>=1;
	}
	return res;
}
void init(){
	for(int i=0;i<5;i++)que.push(U[i]),mp[U[i]]=++tot;
	while(que.size()){
		unsigned long long x=que.front();que.pop();
		f[mp[x]]=x;
		for(int i=0;i<5;i++){
			unsigned long long y=mul(x,U[i]);
			if(mp[y])continue;
			mp[y]=++tot;
			que.push(y);
		}
	}
	for(int i=1;i<=32;i++)
		for(int j=i;j<=32;j++)
			g[i][j]=g[j][i]=mp[mul(f[i],f[j])];
}
struct Node{
	int l,r;
	int s[33];
	int val,lazy;
}tree[M<<2];
void build(int x,int l,int r){
	tree[x].l=l,tree[x].r=r;
	if(l==r){
		for(int i=1;i<=32;i++)tree[x].s[i]=a[l][i]%2019;
		tree[x].val=tree[x].s[28];tree[x].lazy=0;
		return;
	}
	int mid=(l+r)>>1;
	build(x<<1,l,mid);
	build(x<<1|1,mid+1,r);
	for(int i=1;i<=32;i++)tree[x].s[i]=tree[x<<1].s[i]+tree[x<<1|1].s[i];
	tree[x].val=tree[x].s[28];tree[x].lazy=0;
	return;
}
int tmp[35];
void convert(int x,int res){
	for(int i=1;i<=32;i++)tmp[i]=tree[x].s[g[i][res]];
	for(int i=1;i<=32;i++)tree[x].s[i]=tmp[i];
	tree[x].val=tree[x].s[28];
	if(!tree[x].lazy)tree[x].lazy=res;
	else tree[x].lazy=g[tree[x].lazy][res];
}
void pushdown(int x){
	if(tree[x].lazy){
		convert(x<<1,tree[x].lazy);
		convert(x<<1|1,tree[x].lazy);
		tree[x].lazy=0;
	}
}
int query(int x,int l,int r){
	if(tree[x].l>=l && tree[x].r<=r) return tree[x].val;
	pushdown(x);
	int mid=(tree[x].l+tree[x].r)>>1;
	int ans=0;
	if(mid>=l)ans+=query(x<<1,l,r);
	if(mid<r)ans+=query(x<<1|1,l,r);
	return ans;
}
void change(int x,int l,int r,int val){
	if(tree[x].l>=l && tree[x].r<=r){
		convert(x,val);
		return;
	}
	pushdown(x);
	int mid=(tree[x].l+tree[x].r)>>1;
	if(mid>=l)change(x<<1,l,r,val);
	if(mid<r)change(x<<1|1,l,r,val);
	for(int i=1;i<=32;i++)tree[x].s[i]=tree[x<<1].s[i]+tree[x<<1|1].s[i];
	tree[x].val=tree[x].s[28];
	return;
}
int main(){
	init();
	scanf("%d%d",&n,&q);
	for(int i=1;i<=32;i++)a[1][i]=f[i]%mod;
	for(int i=2;i<=n;i++)
		for(int j=1;j<=32;j++)
			a[i][j]=(a[i-1][j]+f[j])%mod;
	build(1,1,n);
	while(q--){
		int l,r;scanf("%d%d",&l,&r);
		int ans=query(1,l,r);
		printf("%d\n",ans);
		change(1,l,r,ans%5+1);
	}
    return 0;
}

