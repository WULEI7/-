#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<map>
#include<vector>
#include<string>
#include<iostream>
using namespace std;
vector<int> course[2500];//ÿ�ſ�һ�У������������ſε�ѧ�� 
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
		mp[t]=name;//Ϊ�˷���֮�����t�ҵ�name 
		int num;//�γ����� 
		scanf("%d",&num);
		int id;//�洢�γ̺��� 
		for(int i=0;i<num;i++){
			scanf("%d",&id);
			course[id].push_back(t);//��¼���ſ�����Щѧ�� 
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
