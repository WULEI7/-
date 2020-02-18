#include <stdio.h>
void main()
{  int i; int a[8]={10,5,4,0,12,18,20,46};
   void jhmaxmin();
   printf("Original array:\n");
   for(i=0;i<8;i++)
   printf("%5d",a[i]);    /*输出原始数组元素*/
   printf("\n");
   jhmaxmin(a,8);
   printf("Array after swaping max and min:\n");
   for(i=0;i<8;i++)
     printf("%5d",a[i]);  /*输出交换后的数组元素*/
   printf("\n"); 
}
void jhmaxmin(int p[],int n)
{  int t,*max=p,*min=p,*end,*q;
   end=p+n;
   *max=*min=*p;
   for(q=p+1;q<end;q++)
   {
      if (*q>*max) max=q;
      if (*q<*min) min=q;
   }
   t=*max; *max=*min; *min=t;
}
