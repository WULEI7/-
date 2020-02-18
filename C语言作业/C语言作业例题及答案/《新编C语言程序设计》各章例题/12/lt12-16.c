#include <stdio.h>
#define PI 3.1415926
#define CIRCLE(R,L,S,V) L=2*PI*R;S=PI*R*R;V=4.0/3.0*PI*R*R*R
main(){
   double R=10.0,L,S,V;
   CIRCLE(R,L,S,V);
   printf("L=%lf\nS=%lf\nV=%lf\n",L,S,V);
}
