#include<stdio.h>
#include<string.h>
#include<math.h>
int main(){
	int a,b;
	char num[110];
	while(scanf("%d%d%s",&a,&b,num)!=EOF){
		if(strcmp(num,"0")==0){
			printf("0\n");
			continue;
		}
		int len=strlen(num);
		long long t=0;
		long long n=0;
		for(int i=0;i<len;i++){
			if(num[i]>='0'&&num[i]<='9'){
				t=num[i]-'0';
			}
			else if(num[i]>='A'&&num[i]<='Z'){
				t=num[i]-'A'+10;
			}
			n+=t*pow(a,len-1-i);
		}
		int q=0;
		char ans[110];
		while(n!=0){
			if(n%b>=0&&n%b<=9){
				ans[q++]=n%b+'0';
			}
			else{
				ans[q++]=(n%b-10)+'a';
			}
			n/=b;
		}
		for(int i=q-1;i>=0;i--){
			printf("%c",ans[i]);
		}
		printf("\n");
		
	}
	return 0;
} 
