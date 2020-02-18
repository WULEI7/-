#include <stdio.h>
int main()
{
	char a[2][7];
	int i,sum1=1,sum2=1;
	gets(a[0]);
	for(i=0;a[0][i]!='\0';i++)
		sum1*=(a[0][i]-'A'+1);
	gets(a[1]);
	for(i=0;a[1][i]!='\0';i++)
		sum2*=(a[1][i]-'A'+1);
	if(sum1%47==sum2%47) printf("GO");
	else printf("STAY");
	return 0;	
}
