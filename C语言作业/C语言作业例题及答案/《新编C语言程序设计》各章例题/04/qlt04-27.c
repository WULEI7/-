#include <stdio.h>
void main()
{  short int ix,ig,is,ib;
   printf("Please input integer ix:");
   scanf("%hd",&ix); /*�Ӽ��̻������*/
   ig=ix%10;
   is=ix/10%10;      //�� is= ix%100/10;
   ib=ix/100;
   printf("%hd�İ�λ������%hd,ʮλ������%hd,��λ������%hd��\n",ix,ib,is,ig);
}
