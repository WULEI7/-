#include<stdio.h> 
#include<string.h>
int main(){
	char x[1010];
	int y;
	while(scanf("%s %d",x,&y)!=EOF){
		int len=strlen(x);
		char s[1010];
		int k=0;
		for(int i=0;i<len;i++){
			s[i]=((k*10+(x[i]-'0'))/y)+'0';
			k=(k*10+(x[i]-'0'))%y;
		}
		
		int count=0;
		for(int i=0;i<len;i++){
			if((s[i]-'0')!=0){
				count=i;
				break;
			}
		}
		for(int i=count;i<len;i++){
			printf("%c",s[i]);
		}
		printf(" %d\n",k);
		
	}
	return 0;
}
