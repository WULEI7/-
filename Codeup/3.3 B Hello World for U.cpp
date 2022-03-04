#include<stdio.h>
#include<string.h>
char str1[100][100];
int main(){
    char str[100];
    scanf("%s",str);
	memset(str1,' ',sizeof(str1));//可能认为输出空格和\0不一样，用memset将str1数组全部置为空格 
    int len=strlen(str);
    int h=(len+2)/3;
    for(int i=0;i<h-1;i++){
    	str1[i][0]=str[i]; 
	}
	for(int j=0;j<len+2-2*h;j++){
		str1[h-1][j]=str[h-1+j];
	}
	for(int i=h-2;i>=0;i--){
		str1[i][len+2-2*h-1]=str[len-i-1];
	}
	for(int i=0;i<h;i++){
		for(int j=0;j<len+2-2*h;j++){
			printf("%c",str1[i][j]);
		}
		printf("\n");
	}
    return 0;
}
