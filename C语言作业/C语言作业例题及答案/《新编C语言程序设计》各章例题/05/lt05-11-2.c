#include <stdio.h>
main(){
   int a,b,c,max,min;
   printf("input three numbers: ");  scanf("%d%d%d",&a,&b,&c);
   if(a>b)
      {max=a;min=b;}
   else
      {max=b;min=a;}
   if(max<c)max=c;
   if(min>c)min=c;
   printf("max=%d\nmin=%d\n",max,min);
}
