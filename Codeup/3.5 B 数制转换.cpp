#include<stdio.h>
#include<string.h>
#include<math.h> 
int main(){
    int a;
    char x[100];
    int b;
    long long n=0;
    while(scanf("%d%s%d",&a,x,&b)!=EOF){
    	if(strcmp(x,"0")==0)
    	{
    		printf("0\n");
    		continue;
		}//ע��ϸ�ڣ�����0��ʱ������ 
        int lenx=strlen(x);
        for(int i=0;i<lenx;i++){
        	long long t;
        	if(x[i]>='0'&&x[i]<='9'){
        		t=x[i]-'0';
			}
			else{
				if(x[i]>='a'&&x[i]<='z')
					t=x[i]-'a'+10;
				else
					t=x[i]-'A'+10;
			}//ע��������ĸ�����Ǵ�Сд 
			n+=t*pow(a,lenx-1-i);
		}
		int q=0;
		char x1[100];
		while(n!=0){
			if(n%b<=9){
				x1[q++]='0'+n%b;
			}
			else{
				x1[q++]='A'+(n%b-10);
			}
			n/=b;
		}
		for(int i=q-1;i>=0;i--){ 
			printf("%c",x1[i]);
		}
        printf("\n");
    }
    return 0;
}
