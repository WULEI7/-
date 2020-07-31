#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
string a[105],b[105];
int main(){
	string mod; 
	bool flag;int n;
	cin>>mod>>flag>>n;
	for(int i=1;i<=n;i++) cin>>a[i],b[i]=a[i];
	if(!flag){
		for(int i=0;i<mod.length();i++){
			if(mod[i]>='A'&&mod[i]<='Z') mod[i]-='A'-'a';
		}for(int i=1;i<=n;i++){
			for(int j=0;j<a[i].length();j++){
				if(a[i][j]<='Z'&&a[i][j]>='A') a[i][j]-='A'-'a';
			}
		}
	}for(int i=1;i<=n;i++){
		for(int j=0;j+mod.length()-1<a[i].length();j++){
			if(a[i].substr(j,mod.length())==mod){
				cout<<b[i]<<endl;break;
			}
		}
	}
}


