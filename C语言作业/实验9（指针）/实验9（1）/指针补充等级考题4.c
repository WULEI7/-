#include <stdio.h>
void fun( int m, int *k, int xx[] )
{
	int i,j,flag;
	*k=0;
	for(i=3;i<=m;i++)
	{
		flag=0;
		for(j=2;j<i;j++)
			if(i%j==0)
			{flag=1;break;}
		if(flag==1) xx[(*k)++]=i;
	}
}
main()
{
   int m, n, zz[100];
   printf( "Please enter an integer number between 10 and 100: \n" );
   scanf(  "%d", &n );
   fun( n, &m, zz );
   printf( "There are %d non-prime numbers less than %d:\n", m, n );
   for( n = 0; n < m; n++ )
      printf( "%4d", zz[n] );
}
