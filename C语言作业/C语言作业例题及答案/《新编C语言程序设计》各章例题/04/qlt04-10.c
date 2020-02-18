#include <stdio.h>
void main()
{  int i=0;
   printf("%d%d%d\n",++i,++i,++i);
   printf("%d%d%d\n",i++,i++,i++);
   i=1;printf("%d %d\n",i++,++i); getch();
}
