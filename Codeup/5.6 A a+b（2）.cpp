#include<stdio.h>
#include<string.h>
int main(){
	char str1[1010];
	char str2[1010];
	while(scanf("%s%s",str1,str2)!=EOF){
		int lena=strlen(str1);
		int lenb=strlen(str2);
		int a[1010]={0};
		int b[1010]={0};
		for(int i=lena-1;i>=0;i--){
			a[i]=str1[lena-i-1]-'0';
		}
		for(int i=lenb-1;i>=0;i--){
			b[i]=str2[lenb-i-1]-'0';
		}
		int c[1010]={0};
		int t;
		int k=0;
		int x=0;
		for(int i=0;i<lena||i<lenb;i++){
			t=a[i]+b[i]+k;
			c[x++]=t%10;
			k=t/10;
		}
		if(k!=0){
			c[x++]=k;
		}
		for(int i=x-1;i>=0;i--){
			printf("%d",c[i]);
		}
		printf("\n");
	}
	return 0;
}