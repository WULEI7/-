#include <stdio.h>
void main(){ int i=8;
  printf("%d,%d  ",++i,--i); printf("i=%d\n",i);
  i=8;printf("%d,%d,%d  ",++i,--i,i++); printf("i=%d\n",i);
  i=8;printf("%d,%d,%d,%d  ",++i,--i,i++,i--); printf("i=%d\n",i);
  i=8;printf("%d,%d,%d,%d,%d  ",++i,--i,i++,i--,-i++); printf("i=%d\n",i);
  i=8;printf("%d,%d,%d,%d,%d,%d  ",++i,--i,i++,i--,-i++,-i--); printf("i=%d\n",i);
}
