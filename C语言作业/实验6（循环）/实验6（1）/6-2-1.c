#include <stdio.h>
main()
{  long long int i=1,n,s=1;
   printf("Please enter n:");
   scanf("%d",&n);
   for(i=1;i<=n;i++)
      s=s*i;   //����n�����󣬹۲�sֵ�ı仯����������
   printf("%d!=%lld\n",n,s);
}
