#include <stdio.h>
void main(){
   float a,b; char c;
   printf("Input expression: a+(-,*,/)b \n");
   scanf("%f%c%f",&a,&c,&b);  //ע�⣺�����Ҫ������һ���������룬��1.0/ 2.0
   printf("%f%c%f=",a,c,b);   // ����������ʽ
   switch(c){
      case '+': printf("%f\n",a+b);break; // break������
      case '-': printf("%f\n",a-b);break;
      case '*': printf("%f\n",a*b);break;
      case '/': printf("%f\n",a/b);break;
      default: printf("input error\n");
   }
}
