#include <stdio.h>
void main(){
  int i=8,k;
  k=++i;              /* k=9,i=9 */
  k=--i;               /* k=8,i=8 */
  k=i++;              /* k=8,i=9 */
  k=i--;               /* k=9,i=8 */
  printf("%d,",++i);     /* i加1后输出故为9 */
  printf("%d,",--i);      /* i减1后输出故为8 */
  printf("%d,",i++);     /* 输出i为8之后再加1(为9) */
  printf("%d,",i--);      /* 输出i为9之后再减1(为8) */
  printf("%d,",-i++);    /* 输出-8之后再加1(为9) */
  printf("%d\n",-i--);    /* 输出-9之后再减1(为8) */
}
