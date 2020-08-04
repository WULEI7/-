#include<stdio.h> 
int main()
{
	int T,i;
	scanf("%d",&T);
	int temp; 
	if(T <= 3500)temp=T;
	else{ 
		for(i=100;i<=100000;i+=100)
		{
			temp=i;
			if(temp<=1500)
				temp=temp*0.03;
			else if(temp>1500&&temp<=4500)
				temp=(temp-1500)*0.1+45;
			else if(temp>4500&&temp<=9000)
				temp=(temp-4500)*0.2+45+300;
			else if(temp>9000&&temp<=35000)
				temp=(temp-9000)*0.25+45+300+900;
			else if(temp>35000&&temp<=55000)
				temp=(temp-35000)*0.3+45+300+900+6500;
			else if(temp>55000&&temp<=80000)
				temp=(temp-55000)*0.35+45+300+900+6500+6000;
			else if(temp>80000)
				temp=(temp-80000)*0.45+45+300+900+6500+6000+8750;
			if(T-3500==i-temp){
				temp=i+3500;
				break;	
			}
		}
	}
	printf("%d\n",temp);
	return 0;
}


