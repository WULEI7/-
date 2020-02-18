#include <stdio.h>
void main()
{  long num;  int n1,n2=0,n3=0,n4=0,n5=0,n;
   printf("Input 0~99999:");  scanf("%ld",&num);
   if (num<0||num>99999){printf("Error input!\n"); exit(1);} //输入错，退出程序。
   if(num>9999) n=5;      //利用if-else-if语句获取输入数的位数
   else if(num>999) n=4;
   else if(num>99) n=3;
   else if(num>9) n=2;
   else n=1;
   printf("n=%d\n",n);         // 输出输入数的位数
   printf("Every figure is "); // 获取并输出输入数的每位数字
   if (n==5){ n5=num/10000; printf("%d,",n5); }
   if (n>=4){ n4=(num-n5*10000)/1000; printf("%d,",n4); }
   if (n>=3){ n3=(num-n5*10000-n4*1000)/100; printf("%d,",n3); }
   if (n>=2){ n2=(num-n5*10000-n4*1000-n3*100)/10; printf("%d,",n2); }
   if (n>=1){ n1=(num-n5*10000-n4*1000-n3*100-n2*10); printf("%d\n",n1); }
   switch(n) //利用switch语句分类输出逆序数字
   {case 5:
     printf("%d's inverted sequence number is %d%d%d%d%d\n",num,n1,n2,n3,n4,n5);
     break;
    case 4:
     printf("%d's inverted sequence number is %d%d%d%d\n",num,n1,n2,n3,n4);break;
    case 3:
     printf("%d's inverted sequence number is %d%d%d\n",num,n1,n2,n3);break;
    case 2:
     printf("%d's inverted sequence number is %d%d\n",num,n1,n2);break;
    case 1:
     printf("%d's inverted sequence number is %d\n",num,n1);break;
   }
}
