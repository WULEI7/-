#include<cstdio>
#include<map>
#include<string>
#include<iostream> 
using namespace std;
int main(){
	int m;
	scanf("%d",&m);
	while(m--){
		int n;
		scanf("%d",&n);
		int num[110];
		int dui[110];
		for(int i=0;i<n;i++){
			cin>>num[i];//输入数字 
		}
		for(int i=0;i<n;i++){
			scanf("%d",&dui[i]);//输入数字对应的组 
		}
		int t[110];
		for(int i=1;i<=n;i++){
			int x=0;
			int y=0;
			map<int,int> mp;
			for(int j=0;j<n;j++){
				if(dui[j]==i){//如果是第i队 
				    y++;
				    x++;
				    //printf("%s\n",num[j].c_str());
					t[x]=num[j];//t里面存着所有第i队的数字 
					mp[t[x]]++;
				}
				else{//就算没有在i队里出现但是只要在其他队出现了，也得放进mp里因为最后都要输出 
					x++;
					t[x]=num[j];
					mp[t[x]];
				}
			}
			if(y>=1){
				printf("%d={",i);
				for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++){
					if(it!=mp.begin()){
						printf(",");
					}
					printf("%d=%d",(it->first),it->second);
				}
				printf("}\n");
			}
			
		}
	}
	return 0;
} 
