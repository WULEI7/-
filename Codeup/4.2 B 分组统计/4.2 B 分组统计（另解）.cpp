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
			cin>>num[i];//�������� 
		}
		for(int i=0;i<n;i++){
			scanf("%d",&dui[i]);//�������ֶ�Ӧ���� 
		}
		int t[110];
		for(int i=1;i<=n;i++){
			int x=0;
			int y=0;
			map<int,int> mp;
			for(int j=0;j<n;j++){
				if(dui[j]==i){//����ǵ�i�� 
				    y++;
				    x++;
				    //printf("%s\n",num[j].c_str());
					t[x]=num[j];//t����������е�i�ӵ����� 
					mp[t[x]]++;
				}
				else{//����û����i������ֵ���ֻҪ�������ӳ����ˣ�Ҳ�÷Ž�mp����Ϊ���Ҫ��� 
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
