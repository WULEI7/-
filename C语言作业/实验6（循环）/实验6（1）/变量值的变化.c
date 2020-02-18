#include <stdio.h> 
int main()
{
       int a=2,  b=10, c=1, i ;
       for(i = c; i<=2 * b; i+= a)
       {
              a = a + 2;
               i = i + 1;
               c = 2 * c;
               if(a >= 10) break;
               b = b- 3;
       }
       printf("i=%d, a=%d, b=%d, c=%d\n", i, a, b, c);
       return 0;
}
