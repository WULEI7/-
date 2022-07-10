#include<cstdio>
#include<iostream> 
#include<string>
using namespace std;
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		string num[110];
		for(int i=0;i<n;i++){
			cin>>num[i];
		}
		string t;
		for(int i=0;i<n-1;i++){
			for(int j=0;j<n-i-1;j++){
				int len1=num[j].length();
				int len2=num[j+1].length();
				if(len1>len2){
					t=num[j];
					num[j]=num[j+1];
					num[j+1]=t;
				}
				else if(len1==len2){
					for(int p=0;p<len1;p++){
						if(num[j][p]>num[j+1][p]){
							t=num[j];
							num[j]=num[j+1];
							num[j+1]=t;
							break;
						}
						else if(num[j][p]<num[j+1][p])//如果当前位小于，也要立即跳出 
							break;
					}
				}
			}
		}
		for(int i=0;i<n;i++){
			printf("%s\n",num[i].c_str());
		}
	}
	return 0;
}
