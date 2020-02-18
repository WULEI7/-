#include <stdio.h>
void main()
{  short int ix,ig,is,ib;
   printf("Please input integer ix:");
   scanf("%hd",&ix); /*从键盘获得数据*/
   ig=ix%10;
   is=ix/10%10;      //或 is= ix%100/10;
   ib=ix/100;
   printf("%hd的百位数字是%hd,十位数字是%hd,个位数字是%hd。\n",ix,ib,is,ig);
}
