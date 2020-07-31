#include<bits/stdc++.h>
using namespace std;
int in[105]; 
string elements[105],id[105];
int pre[105];
map<string,int>number;  //元素和id对应数字
vector<int>pos[105];    //元素和Id所在行的集合 
vector<int>ans[105];

string fun(string t){
	for(int i=0;i<t.length();i++) if(t[i]>='A'&&t[i]<='Z') t[i]-='A'-'a';
	return t;
}

string jie[105];

int main(){
	int n,m;cin>>n>>m;int numb=0;getchar();
	for(int i=1;i<=n;i++){
		string t;int num=0;getline(cin,t);
		int flag=0;
		for(int j=0;j<t.length();j++){
			if(t[j]=='.') num++;
			else if(t[j]==' '){
				flag=j;break;
			}
		}if(!flag) elements[i]=fun(t.substr(num,t.length()-num));
		else{
			elements[i]=fun(t.substr(num,flag-num));
			id[i]=t.substr(flag+1,t.length()-flag-1);
			
		}if(!number[elements[i]]) number[elements[i]]=++numb;
		pos[number[elements[i]]].push_back(i);
		if(!number[id[i]]) number[id[i]]=++numb;
		pos[number[id[i]]].push_back(i);
		//cout<<elements[i]<<endl;
		
		if(i!=1){
			pre[i]=in[num-2];
			
		}in[num]=i; 
	}
	
	for(int i=1;i<=m;i++){
		string t;getline(cin,t);int wei=0,k=0;//cout<<t<<' '<<i<<endl;
		/*
		string aa=t.substr(0,1),bb=t.substr(0,1);
		if(aa==bb) cout<<1<<endl;
		else cout<<0<<endl;*/
		
		for(int j=0;j<t.length();j++){
			if(t[j]==' ') jie[++k]=t.substr(wei,j-wei),wei=j+1;
		}jie[++k]=t.substr(wei,t.length()-wei);
		int start,now,tep;
		for(int j=1;j<=k;j++) if(jie[j][0]!='#') jie[j]=fun(jie[j]);
		for(int j=0;j<pos[number[jie[k]]].size();j++){
			tep=k;
			start=pos[number[jie[k]]][j];tep--;now=start;
			//cout<<start<<endl;
			while(now){//cout<<elements[now]<<endl;
				if(!tep){
					ans[i].push_back(start);break;
				}//cout<<elements[now]<<' '<<jie[tep]<<' '<<1<<endl;
				now=pre[now];
				if((jie[tep][0]=='#'&&id[now]==jie[tep])||(jie[tep][0]!='#'&&elements[now]==jie[tep])) tep--;
				//else break;
				if(!tep){
					ans[i].push_back(start);break;
				}
				
			}
		}
		
	}for(int i=1;i<=m;i++){
		cout<<ans[i].size()<<' ';
		for(int j=0;j<ans[i].size();j++) cout<<ans[i][j]<<' ';
		cout<<endl;
	}
} /*
12 5
html
..head
....title
..body
....h1
....P #subtitle
....div #main
......h2
......P #one
......div
........o
..........p #two
p
#subtitle
h3
DIv p
#main div #two
*/

