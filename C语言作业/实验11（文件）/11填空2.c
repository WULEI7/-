#include <stdio.h>
#include <stdlib.h>
void fun(char *s,int a,double f)
{  FILE *fp;
   char str[100],str1[100],str2[100];
   int a1;double f1;
   fp=fopen("file1.txt","w");
   fprintf(fp, "%s %d %f\n",s,a,f);
   fclose(fp);
   fp=fopen("file1.txt", "r");
   fscanf(fp,"%s%s%s",str,str1,str2);
   fclose(fp);
   a1=atoi(str1);
   f1=atof(str2);
   printf("Result: %s %d %f\n",str,a1,f1);
}
main()
{  char a[10]= "Hello!";
   int b=12345;
   double c=98.76;
   fun(a,b,c);
}
