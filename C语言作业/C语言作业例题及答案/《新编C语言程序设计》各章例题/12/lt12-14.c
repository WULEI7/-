#include <stdio.h>
#define R (3.0)
#define PI (3.1415926)
#define L (2)*(PI)*(R)
#define begin {
#define end }
#define forever for(;;)
void main()
begin       /* { */
  printf("L=%f", L);
  #undef PI /* ȡ����PI�ĺ궨��*/
  forever;  /* for(;;); ����ѭ��*/
end         /* } */
