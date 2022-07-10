#include<cstring>
#include<cstdio>
struct bign{
	int len;
	int d[1010];
	bign(){
		len=0;
		memset(d,0,sizeof(d));
	}
};
bign change(char str[]){
	bign a;
	a.len=strlen(str);
	for(int i=0;i<a.len;i++){
		a.d[i]=str[a.len-1-i]-'0';
	}
	return a;
}
bign add(bign a,bign b){
	int t;
	bign c;
	int carry=0;
	for(int i=0;i<a.len||i<b.len;i++){
		t=a.d[i]+b.d[i]+carry;
		c.d[c.len++]=t%10; 
		carry=t/10;	
	}
	if(carry!=0){
		c.d[c.len++]=carry; 
	}
	return c;
}
int main(){
	char str1[1010];
	char str2[1010];
	while(scanf("%s%s",str1,str2)!=EOF){
		bign a=change(str1);
		bign b=change(str2);
		bign c=add(a,b);
		for(int i=c.len-1;i>=0;i--){
			printf("%d",c.d[i]);
		}
		printf("\n");	
	}
	return 0;
}
