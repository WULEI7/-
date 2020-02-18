#include <stdio.h>
void main(){
   int i=8;
   printf("%d,",++i);printf("%d,",--i); printf("%d,",i++); //多行并列格式
   printf("%d,",i--);printf("%d,",-i++); printf("%d\n",-i--);
}
