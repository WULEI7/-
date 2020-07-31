#include<bits/stdc++.h>
using namespace std;
string s[105],t;
int n,m;
map<string,string>mp; 
int main(){
	cin>>n>>m;getchar();
	for(int i=1;i<=n;i++)getline(cin,s[i]);
	for(int i=1;i<=m;i++){
		getline(cin,t);
		string x="",y="";
		int j=0;
		while(t[j]!=' ')x+=t[j++];j+=2;
		while(t[j]!='"')y+=t[j++];
		mp[x]=y;
	}
	for(int i=1;i<=n;i++){
		int sz=(int)s[i].size();
		for(int j=0;j<sz;j++){
			if(j==sz-1 || (s[i][j]!='{' || s[i][j+1]!='{')){
				cout<<s[i][j];
				continue;
			}
			j+=3;
			string x="";
			while(s[i][j]!=' ')x+=s[i][j++];
			j+=2;
			cout<<mp[x];
		}
		cout<<"\n";
	}
    return 0;
}

