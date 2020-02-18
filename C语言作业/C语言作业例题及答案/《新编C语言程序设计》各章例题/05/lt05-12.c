#include <stdio.h>
void main(){
   float a,b; char c;
   printf("Input expression: a+(-,*,/)b \n");
   scanf("%f%c%f",&a,&c,&b);  //注意：运算符要紧跟第一个数来输入，如1.0/ 2.0
   printf("%f%c%f=",a,c,b);   // 输出算术表达式
   switch(c){
      case '+': printf("%f\n",a+b);break; // break不能少
      case '-': printf("%f\n",a-b);break;
      case '*': printf("%f\n",a*b);break;
      case '/': printf("%f\n",a/b);break;
      default: printf("input error\n");
   }
}
