#include<bits/stdc++.h>
#pragma GCC optimize(3,"Ofast","inline")
using namespace std;
int n,m,t,k,tot;
vector<int>g[505];
int v[30005][505];
struct Node{
	int len,val;
	Node *nxt;
	Node(int len,int val,Node *nxt=NULL):len(len),val(val),nxt(nxt){}
}*p[505];
struct Link{
	int type;
	int id,time;
	Node *back;
	Link(int type,int id,int time,Node *back=NULL):type(type),id(id),time(time),back(back){}
};
deque<Link>que;
void bfs(int end){
	while(que.size() && que.front().time<=end){
		Link y=que.front();que.pop_front();
		if(y.back->len>p[y.id]->len || (y.back->len==p[y.id]->len && y.back->val<p[y.id]->val)){
			p[y.id]=y.back;
			int sz=(int)g[y.id].size();
			for(int i=0;i<sz;i++){
				int c=g[y.id][i];
				if(v[y.type][c])continue;
				v[y.type][c]=1;
				que.push_back((Link){y.type,c,y.time+t,p[y.id]});
			}
		}
	}
}
int ans[30005];
void print(Node *c){
	int l=c->len;
	printf("%d ",l);
	if(l>=500){
		cout<<"NO\n";
		exit(0);
	}
	for(int i=l;i;i--,c=c->nxt)ans[i]=c->val;
	for(int i=1;i<=l;i++)printf("%d ",ans[i]);
	printf("\n");
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<=m;i++){
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for(int i=1;i<=n;i++)p[i]=new Node(1,0);
	scanf("%d%d",&t,&k);
	while(k--){
		int x,y,z;scanf("%d%d",&x,&y);
		char c=getchar();
		if(c!='\n'){
			scanf("%d",&z);
			bfs(y);
			Node *tmp=new Node(p[x]->len+1,z,p[x]);
			que.push_front(Link(++tot,x,y,tmp));
		}
		else{
			bfs(y);
			print(p[x]);
		}
	}
    return 0;
}

