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
vector<set<int> >e(10005);
int main()
{
	fast;
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		e[b-1].insert(a-1);
		e[a-1].insert(b-1);
	}
	int cnt=0;
	for(int i=0;i<n;i++)	if(e[i].size()&1) cnt++;
	if(cnt!=0&&cnt!=2) {
		cout<<"-1\n";
		return 0;
	}
	if(cnt==2&&!(e[0].size()&1)) {
		cout<<"-1\n";
		return 0;
	}
	vector<int>path,cir;
	path.pb(0);
	while(!path.empty()&&path.size()+cir.size()<m+1){//hierholzer's Algorithm
		int cur=path.back();
		if(e[cur].empty()){
			path.pop_back();
			cir.pb(cur);
		}
		else{
			int v=*e[cur].begin();
			e[cur].erase(e[cur].begin());
			e[v].erase(cur);//so I use set to make erasing more easily. 
			path.pb(v);
		}
	}
	if(path.empty()){
		cout<<"-1\n";
		return 0;
	}
	while(!cir.empty()){
		path.pb(cir.back());
		cir.pop_back();
	}
	cout<<1<<' ';
	for(int i=1;i<=m;i++) cout<<path[i]+1<<' ';
	return 0;
}
 
//*More about hierholzer's Algorithm:
//Step 1: choose arbitatry node then traverse all adjacent edges.
//Step 2: do BFS or DFS to visit adjacent nodes. Delete all edges you've visited during searching.
//Step 3: If the current node has no adjacent edge, push this node into a stack.(I use vector here)
//Step 4: Output nodes in stack in inverted order.

