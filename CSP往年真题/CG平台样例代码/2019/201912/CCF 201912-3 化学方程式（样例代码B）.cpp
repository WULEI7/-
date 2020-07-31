#include<bits/stdc++.h>
#pragma GCC optimize(3,"Ofast","inline")
using namespace std;
int T,to;
string tmp;
string l,r,c;
map<string,int>ele[2];
map<string,int>::iterator it[2];
struct Node{
	string elename;
	int loc,time;
};
vector<Node>v;
vector<int>kk;
void solve(string x,int id){
	int xishu=0;
	int loc=0,sz=(int)x.size();
	while(isdigit(x[loc]))xishu=xishu*10+(x[loc++]-'0');
	xishu=max(xishu,1);
	v.clear();kk.clear();
	string eletmp="";
	for(;loc<sz;loc++){
		if(x[loc]>='A' && x[loc]<='Z'){
			if(!eletmp.empty())v.push_back((Node){eletmp,loc-1,1}),eletmp="";
			eletmp+=x[loc];
			continue;
		}
		if(x[loc]>='a' && x[loc]<='z'){
			eletmp+=x[loc];
			continue;
		}
		if(isdigit(x[loc])){
			int num=0,p=loc-eletmp.size();
			while(loc<sz && isdigit(x[loc]))num=num*10+(x[loc++]-'0');loc--;
			v.push_back((Node){eletmp,p,num});eletmp="";
			continue;
		}
		if(eletmp.size())v.push_back((Node){eletmp,loc-eletmp.size(),1});eletmp="";
		if(x[loc]=='('){
			kk.push_back(loc);
			continue;
		}
		if(!eletmp.empty()){
			v.push_back((Node){eletmp,loc-eletmp.size(),1});
			eletmp="";
		}
		int back=(int)v.size()-1;
		int pre=kk[(int)kk.size()-1];kk.pop_back();
		int mul=0;loc++;
		while(loc<sz && isdigit(x[loc]))mul=mul*10+(x[loc++]-'0');if(loc<sz)loc--;
		mul=max(mul,1);
		while(back>=0){
			if(v[back].loc<pre)break;
			v[back].time*=mul;
			back--;
		}
	}
	if(eletmp.size())v.push_back((Node){eletmp,sz,1});
	sz=(int)v.size();
	for(int i=0;i<sz;i++)ele[id][v[i].elename]+=xishu*v[i].time;
}
int main(){
	scanf("%d",&T);
	while(T--){
		cin>>c;
		ele[0].clear();ele[1].clear();tmp="";
		l="",r="";
		for(int i=0;i<c.size();i++){
			if(c[i]!='=')l+=c[i];
			else{
				i++;
				while(i<c.size())r+=c[i++];
			}
		}
		for(int i=0,len=l.size();i<len;i++){
			if(l[i]=='+')solve(tmp,0),tmp="";
			else tmp+=l[i];
		}
		solve(tmp,0);tmp="";
		for(int i=0,len=r.size();i<len;i++){
			if(r[i]=='+')solve(tmp,1),tmp="";
			else tmp+=r[i];
		}
		solve(tmp,1);tmp="";
		it[0]=ele[0].begin();it[1]=ele[1].begin();
		if(ele[0].size()!=ele[1].size()){
			cout<<"N\n";
			continue;
		}
		bool flag=true;
		while(it[0]!=ele[0].end()){
			if(it[0]->first!=it[1]->first || it[0]->second!=it[1]->second){
				cout<<"N\n";flag=false;
				break;
			}
			it[0]++,it[1]++;
		}
		if(flag)cout<<"Y\n";
	}
    return 0;
}


