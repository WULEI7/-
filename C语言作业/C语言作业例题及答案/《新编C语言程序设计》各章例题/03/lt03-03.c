#include <stdio.h>
void main()
{ //01111111111111111111111111111111->4字节最大正整数,16进制表示为0x7fffffff
  int i=0x7fffffff;
  //11111111111111111111111111111111->4字节最大无符号正整数,16进制表示为0xffffffff
  unsigned int ui=0xffffffff;
  //0111111111111111->2字节最大正整数，十六进制表示为0x7fff
  short int si=0x7fff;
  //0111111111111111->2字节最大无符号正整数，十六进制表示为0xffff
  unsigned short int usi=0xffff;
  long int li=0x7fffffff;
  unsigned long ul=0xffffffff;
  printf("%d \t%d\n",i,i+1);               //输出最大正整数及其加1
  printf("%u \t%u\n",ui,ui+1);             //输出最大无符号整数及其加1
  printf("%d",si);  printf(" \t\t%d\n",++si); //输出最大短整数及其加1
  printf("%u",usi); printf(" \t\t%u\n",++usi);//输出最大无符号短整数及其加1
  printf("%ld \t%ld\n",li,li+1);           //输出最大长整数及其加1
  printf("%u \t%u\n",ul,ul+1);             //输出最大无符号长整数及其加1
}
