#include <stdio.h>
void main()
{  double x,y; float a,b,c,d;
   x=5.67; y=6.789;
   a=7.89f; b=8.9f;
   printf("sizeofx=%d, sizeofa=%d\n",sizeof(x),sizeof(a));
   c=x+a;  d=y+b;       /*ªÏ∫œ‘ÀÀ„*/
   printf("c=x+a=%f,d=y+b=%f\n",c,d);
   printf("sizeofx+a=%d, sizeofc=%d\n",sizeof(x+a),sizeof(c));
   printf("sizeofx=%d, sizeofa=%d\n",sizeof(x),sizeof(a));
}

