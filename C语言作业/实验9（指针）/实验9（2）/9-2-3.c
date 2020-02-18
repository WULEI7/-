#include <stdio.h>
#include<string.h>
void main()
{  int i,a[26];
   char ch,str[80],*p=str;
   gets(str);   /*获取字符串*/
   for(i=0;i<26;i++)
      a[i]=0;   /*初始化字符个数*/
   while (*p)
   {  ch=*(p++); /*移动指针统计不同字符出现的次数*/
      ch=ch>='A' &&ch<='Z' ?ch+'a'-'A':ch; /*大小写字符转换*/
      if ('a'<=ch&&ch<='z') a[ch-'a']++;
   }
   for(i=0;i<26;i++) printf("%2c",'a'+i); /*输出26个字母*/
   printf("出现的次数为：\n");
   for(i=0;i<26;i++) printf("%2d",a[i]); /*输出各字母出现次数*/
   printf("\n");
}
