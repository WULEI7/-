#include <stdio.h>
main()
{  int i,n;
	float t,s=0; 
   scanf("%d",&n);
   for(i=1;i<=n;i++)
   {
   t=(float)1/i;
   s=s+t;
   }    //�۲�s,t��ֵ�ı仯����������
   printf("s=%f\n",s);
}
