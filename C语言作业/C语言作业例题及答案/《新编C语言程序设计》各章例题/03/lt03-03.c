#include <stdio.h>
void main()
{ //01111111111111111111111111111111->4�ֽ����������,16���Ʊ�ʾΪ0x7fffffff
  int i=0x7fffffff;
  //11111111111111111111111111111111->4�ֽ�����޷���������,16���Ʊ�ʾΪ0xffffffff
  unsigned int ui=0xffffffff;
  //0111111111111111->2�ֽ������������ʮ�����Ʊ�ʾΪ0x7fff
  short int si=0x7fff;
  //0111111111111111->2�ֽ�����޷�����������ʮ�����Ʊ�ʾΪ0xffff
  unsigned short int usi=0xffff;
  long int li=0x7fffffff;
  unsigned long ul=0xffffffff;
  printf("%d \t%d\n",i,i+1);               //�����������������1
  printf("%u \t%u\n",ui,ui+1);             //�������޷������������1
  printf("%d",si);  printf(" \t\t%d\n",++si); //����������������1
  printf("%u",usi); printf(" \t\t%u\n",++usi);//�������޷��Ŷ����������1
  printf("%ld \t%ld\n",li,li+1);           //���������������1
  printf("%u \t%u\n",ul,ul+1);             //�������޷��ų����������1
}
