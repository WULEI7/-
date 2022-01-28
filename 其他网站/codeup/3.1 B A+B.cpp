#include<stdio.h>
#include<string.h>
#include<math.h>
int main(){
    char a[20];
    char b[20];
    while(scanf("%s%s",a,b)!=EOF){
        int lena=strlen(a);
		int lenb=strlen(b);
		int a1=0,b1=0,x=0,x1=0;
		for(int i=lena-1;i>=0;i--){
			if(a[i]!=','&&a[i]!='-'){
				a1=a1+(a[i]-'0')*(pow(10,x++));
		    }
		    if(a[i]=='-'){
		    	a1=-a1;
			}
		}
		for(int i=lenb-1;i>=0;i--){
			if(b[i]!=','&&b[i]!='-'){
				b1=b1+(b[i]-'0')*(pow(10,x1++));
			}
			if(b[i]=='-'){
				b1=-b1;
			}	
		}
		printf("%d\n",a1+b1);
    }
    return 0;
}
