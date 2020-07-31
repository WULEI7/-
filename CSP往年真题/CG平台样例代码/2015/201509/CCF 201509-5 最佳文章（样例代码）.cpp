#include<bits/stdc++.h>
using namespace std;
const int M=1e4+10;
const int mod=1e9+7;
const long long INF=0x3f3f3f3f3f3f3f3f;
char s[M];
int n,rear,nxt[M][28],Fail[M],e[M];
long long m;
typedef vector<long long>vec;
typedef vector<vec>matrix;
queue<int>que;
int init(){
	e[++rear]=0;
	for(int i=0;i<26;i++)nxt[rear][i]=-1;
	return rear;
}
void add(){
	int len=strlen(s),now=1;
	for(int i=0;i<len;i++){
		int x=s[i]-'a';
		if(nxt[now][x]==-1)nxt[now][x]=init();
		now=nxt[now][x];
	}
	e[now]++;
}
matrix build(){
	Fail[1]=1;
	for(int i=0;i<26;i++){
		if(nxt[1][i]==-1)nxt[1][i]=1;
		else{
			Fail[nxt[1][i]]=1;
			que.push(nxt[1][i]);
		}
	}
	while(que.size()){
		int x=que.front();que.pop();
		e[x]+=e[Fail[x]];
		for(int i=0;i<26;i++){
            if(nxt[x][i]==-1)nxt[x][i]=nxt[Fail[x]][i];
            else{
                Fail[nxt[x][i]]=nxt[Fail[x]][i];
                que.push(nxt[x][i]);
            }
        }
	}
	matrix c(rear,vec(rear));
	for(int i=0;i<c.size();i++)
        for(int j=0;j<c[0].size();j++) 
            c[i][j]=-INF;
    for(int i=1;i<=rear;i++)
    	for(int j=0;j<26;j++){
    		int x=nxt[i][j];
    		c[x-1][i-1]=e[x];
		}
    return c;	
}
matrix matmul(matrix a,matrix b){
	matrix c(a.size(), vec(b[0].size()));
	for(int i=0;i<c.size();i++)
        for(int j=0;j<c[0].size();j++) 
            c[i][j]=-INF;
    for(int i=0;i<a.size();i++)
    	for(int j=0;j<b[0].size();j++)
    		for(int k=0;k<b.size();k++)
    			if(a[i][k]+b[k][j]>=0)
    				c[i][j]=max(c[i][j],a[i][k]+b[k][j]);
    return c;
}
matrix matpow(matrix a,long long m){
	matrix b=a;m--;
	while(m){
		if(m&1)b=matmul(b,a);
		a=matmul(a,a);
		m>>=1;
	}
	return b;
}
int main(){
	cin>>n>>m;
	init();
	for(int i=1;i<=n;i++){
		cin>>s;
		add();
	}
	matrix a=build();
	a=matpow(a,m);
	long long ans=0;
	for(int i=0;i<rear;i++)ans=max(ans,a[i][0]);
	cout<<ans;
    return 0;
}

