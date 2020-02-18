#include <stdio.h>
#define P printf
#define D "%d\n"
#define F "%f\n"
main(){
   int a=5, c=8, e=11;
   float b=3.8, d=9.7, f=21.08;
   P(D F,a,b);  //C”Ô—‘÷–ø…“‘£∫"%d\n""%f\n"=="%d\n%f\n"
   P(D F,c,d);
   P(D F,e,f);
}
