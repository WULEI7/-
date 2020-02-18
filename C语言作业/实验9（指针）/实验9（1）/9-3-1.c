#include <stdio.h>
int main()
{  int x,y,z,max,*px,*py,*pz,*pmax;
   scanf("%d%d%d",&x,&y,&z);
   px=&x; py=&y; pz=&z; pmax=&max;
   *pmax=*px;               
   if(*pmax<*py) *pmax=*py;
   if(*pmax<*pz) *pmax=*pz;         
   printf("max=%d\n",max);
}
