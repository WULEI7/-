#include<math.h>
#include<stdio.h>
int main()
{
	char x[50]; 
	int i=1,t;
	long int y=0;
		scanf("%s",&x);
	for(i=0;x[i];i++){
	if(x[i]>='A'&&x[i]<='F'){
		t=x[i]-55;
	}
	else t=x[i]-'0';
	y=y*16+t;
}		
	printf("%ld",y);	
	return 0;
}
