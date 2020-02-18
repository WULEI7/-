#include<stdio.h>
int main()
{
       int n,m;
       int indiv , ten , hundred, thousand;
       printf("input a number(1000~9999):\n");
       scanf("%d",&n);
       indiv=n % 10;                   //通过取余方法获取个位上的数字
       ten = n / 10 % 10 ;     //通过整除和取余方法获取十位上的数字
       hundred = n / 100 % 10;    //通过整除方法获取百位上的数字
       thousand = n / 1000; 
	   indiv=(indiv+7)%10;
	   ten=(ten+7)%10;
	   hundred=(hundred+7)%10;
	   thousand=(thousand+7)%10;
	   m=ten*1000+indiv*100+thousand*10+hundred;
       printf("%d加密的结果是%d\n",n,m);
       return 0;
}


