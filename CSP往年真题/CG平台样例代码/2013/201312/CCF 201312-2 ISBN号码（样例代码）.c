#include<stdio.h>
#include<string.h>
int main(){
	char c[13];
	int k=1,sum=0,i;
	scanf("%s",c);
	
	for(i=0;i<12;i++){
		if(c[i]=='-')continue;
		else{
			sum+=(c[i]-48)*k;
			k++;
		}
	}
	sum%=11;
	if(sum==10)sum='X';
	else sum+=48;
	if(sum==c[12])printf("Right");
	else{
		for(i=0;i<12;i++)printf("%c",c[i]);
		printf("%c",sum);
	}
	return 0;
}

