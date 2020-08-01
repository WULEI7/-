#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+5;
ll dp[N];
bool v[N]; 
int x[N],y[N],c[N];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int main(){
	int n,m,k,d;scanf("%d%d%d%d",&n,&m,&k,&d);
	queue<pair<int,int> >q;
	for(int i=1;i<=m;i++){
		int a,b;scanf("%d%d",&a,&b);
		q.push(make_pair((a-1)*n+b,0));
		v[(a-1)*n+b]=1;
	}for(int i=1;i<=k;i++){
		scanf("%d%d%d",&x[i],&y[i],&c[i]);
	}for(int i=1;i<=d;i++){
		int a,b;scanf("%d%d",&a,&b);
		v[(a-1)*n+b]=1;
	}while(q.size()){
		int a=q.front().first,b=q.front().second;
		q.pop();
		int xx=(a+n-1)/n,yy=a-(xx-1)*n;
		for(int i=0;i<4;i++){
			int mx=xx+dx[i];
			int my=yy+dy[i];
			int mm=(mx-1)*n+my;
			if(mx>=1&&mx<=n&&my>=1&&my<=n&&v[mm]==0){
				v[mm]=1;
				dp[mm]=b+1;
				q.push(make_pair(mm,b+1));
			}
		}
	}ll ans=0;
	for(int i=1;i<=k;i++){
		ans+=(ll)c[i]*dp[(x[i]-1)*n+y[i]];
	}printf("%lld",ans);
}

