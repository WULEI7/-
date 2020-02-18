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
  #undef PI /* 取消对PI的宏定义*/
  forever;  /* for(;;); 无限循环*/
end         /* } */
