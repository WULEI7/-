#include <stdio.h>
main(){
   char c; printf("input a character: ");
   c=getchar();
   if(c<32)                     //�� if(iscntrl(c)) ʹ���ж��ַ��Ŀ⺯������ͬ
      printf("This is a control character\n");
   else if(c>='0'&&c<='9')      //�� else if(isdigit(c))
      printf("This is a digit\n");
   else if(c>='A'&&c<='Z')      //�� else if(isupper(c))
      printf("This is a capital letter\n");
   else if(c>='a'&&c<='z')      //�� else if(islower(c))
      printf("This is a small letter\n");
   else
      printf("This is an other character\n");
}
