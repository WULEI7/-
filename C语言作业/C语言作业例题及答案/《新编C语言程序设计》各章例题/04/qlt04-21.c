#include <stdio.h>
void main(){
  char a,b,c; printf("input character to a,b,c\n");
  scanf("%c %c %c",&a,&b,&c);
  printf("%d,%d,%d\n%c,%c,%c\n",a,b,c,a-32,b-32,c-32); //大小写字母ASCII相差32
  printf("%c,%c,%c\n",toupper(a),toupper(b),toupper(c));//也可用库函数来实现转换
}
