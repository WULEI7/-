#include <stdlib.h>  /*srand()��rand()������ͷ�ļ�*/
#include <stdio.h>
void main()
{ unsigned int n;
  printf("Please input n:"); scanf("%u", &n);
  srand(n);  /*���Ӻ�������ʼ��rand()��Win-TC��Ҳ����randomize()����ʼ��*/
  printf("%8d",rand());/*����rand()����һ�Σ����һ���������Win-TC����random(n)*/
  printf("%8d",rand());  /*����rand()����һ�Σ������һ�������*/
  printf("%8d\n",rand());/*����rand()����һ�Σ������һ�������*/
}
