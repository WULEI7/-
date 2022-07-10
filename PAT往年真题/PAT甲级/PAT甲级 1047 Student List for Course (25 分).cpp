#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<map>
#include<vector>
#include<string>
#include<iostream>
using namespace std;
vector<int> course[2500];//每门课一行，里面存放上这门课的学生 
map<int,string> mp;
int hashfuc(string a){
	int stid=0;
	for(int i=0;i<3;i++){
		stid=stid*26+(a[i]-'A');
	}
	stid=stid*10+(a[3]-'0');
	return stid;
}
int main(){
	int m,n;
	scanf("%d%d",&m,&n);
	while(m--){
		string name;
		cin>>name;
		int t=hashfuc(name);
		mp[t]=name;//为了方便之后根据t找到name 
		int num;//课程总数 
		scanf("%d",&num);
		int id;//存储课程号码 
		for(int i=0;i<num;i++){
			scanf("%d",&id);
			course[id].push_back(t);//记录这门课有哪些学生 
		}
	}
	for(int i=1;i<=n;i++){
		printf("%d %d\n",i,course[i].size());
		sort(course[i].begin(),course[i].end());
		int size=course[i].size();
		for(int j=0;j<size;j++){
			printf("%s\n",mp[course[i][j]].c_str());
			//cout<<mp[course[i][j]]<<endl;
		}
	} 
	return 0;
}
