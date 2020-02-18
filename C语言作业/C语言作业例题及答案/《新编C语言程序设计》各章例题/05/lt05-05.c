#include <stdio.h>
main(){
   char c; printf("input a character: ");
   c=getchar();
   if(c<32)                     //或 if(iscntrl(c)) 使用判断字符的库函数，下同
      printf("This is a control character\n");
   else if(c>='0'&&c<='9')      //或 else if(isdigit(c))
      printf("This is a digit\n");
   else if(c>='A'&&c<='Z')      //或 else if(isupper(c))
      printf("This is a capital letter\n");
   else if(c>='a'&&c<='z')      //或 else if(islower(c))
      printf("This is a small letter\n");
   else
      printf("This is an other character\n");
}
