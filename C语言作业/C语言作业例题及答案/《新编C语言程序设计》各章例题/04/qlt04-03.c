void main(){
   char c1,c2; printf("input a character\n");
   c1=getchar();c2=getchar(); //仍然输入单个字符，c2接受回车键“字符”
   putchar(c1); putchar(c2); putchar('\n');
   printf("%d  %d\n",c1,c2);  //本语句详见下一节，输出两字符ASCII码整数值
}