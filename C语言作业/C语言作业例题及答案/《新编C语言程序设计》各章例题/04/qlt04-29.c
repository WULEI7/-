#include <stdlib.h>
#include <time.h>  // time()�����ͷ�ļ�
#include <stdio.h>
void main()
{  unsigned short count;
   srand((unsigned)time(NULL));  /*���Ӻ���*/
   count= rand()%100+3; printf("%hu\n",count);
   count= rand()%100+3; printf("%hu\n",count);
   count= rand()%100+3; printf("%hu\n",count);
}
