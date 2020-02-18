#include <stdio.h>
#include <stdlib.h>
#define N 10
void main()
{  struct worker
   {  char id[5];
      char name[10];
      int salary;
   } s[N];
   int i; FILE *fp;
   for(i=0;i<N;i++)
   {  printf("Input record:");
      scanf("%s %s %d",s[i].id,s[i].name,&s[i].salary);
      printf("\n");
   }
   if ((fp=fopen("worker.dat","wb"))==NULL)
   {  printf("File not open."); abort(); }
   for(i=0;i<N;i++)
      fwrite(&s[i],sizeof(struct worker),1,fp);
   fclose(fp);
   if ((fp=fopen("worker.dat","rb"))==NULL)
   {   printf("File not open."); abort(); }
   for(i=0;i<N;i++)
   {
      fread(&s[i],sizeof(s[i]),1,fp);
      printf("%s %s %d\n",s[i].id,s[i].name,s[i].salary);
   }
   fclose(fp);
}
