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
string base="0123456789ABCDEF";
string s[1007];
string cal(int st,int label,int n){
	string temp="00000000";
	for(int i=0;i<n;i++){
		if(i==st) continue;
		string t=s[i].substr(label,8);
		int sz=t.size();
		for(int j=0;j<sz;j++){
			int x,y;
			if(temp[j]>='0'&&temp[j]<='9') x=temp[j]-'0';
			else x=temp[j]-'A'+10;
			if(t[j]>='0'&&t[j]<='9') y=t[j]-'0';
			else y=t[j]-'A'+10;
			temp[j]=base[(x^y)];
		}
	}
}

int main()
{
	fast;
	int n,ss,l;
	int maxx=0;
	cin>>n>>ss>>l;
	for(int i=0;i<l;i++){
		int a;
		cin>>a;
		cin>>s[a];
		maxx=s[a].size()/8/ss;
	}
	int m;
	cin>>m;
	while(m--){
		int b;
		cin>>b;
		int tnum=b/ss/(n-1);
		int p=n-tnum%n-1;
		int st=(p+1+(b-tnum*(n-1)*ss)/ss)%n;
		int label=(b%ss+tnum*ss)*8;
		if(tnum>=maxx||s[st].size()==0&&n-l>=2) cout<<"-\n";
		else if(s[st].size())	 cout<<s[st].substr(label,8)<<'\n';
		else{
			cout<<cal(st,label,n)<<'\n';
		}
	}
	return 0;
}

