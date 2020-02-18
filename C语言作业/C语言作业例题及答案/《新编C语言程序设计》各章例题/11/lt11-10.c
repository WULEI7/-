#include <stdio.h>
void main()
{  char str[80];int h1,h2,m1,m2,s1,s2;
   long t_start,t_end, interval; int c; double fee = 0;
   FILE *fin;
   fin = fopen("dial.txt","r");
   if (!fin) return -1;
   while (!feof(fin)) {  
     if (!fgets(str,80,fin)) break;
     if (str[0]=='i') continue;
     h1 =(str[2]-48) * 10 + str[3]-48;
     m1 =(str[5]-48) * 10 + str[6]-48;
     s1 =(str[8]-48) * 10 + str[9]-48;
     h2 =(str[11]-48) * 10 + str[12]-48;
     m2 =(str[14]-48) * 10 + str[15]-48;
     s2 =(str[17]-48) * 10 + str[18]-48;
     t_start =h1*60*60 + m1*60 + s1;   /* 通话开始时间 */
     t_end = h2*60*60 + m2*60 + s2;    /* 通话结束时间 */
     if (t_end<t_start)                /* 若通话开始和结束时间跨日*/
        interval = 24*60*60-t_start + t_end;
     else interval =t_end-t_start;
     c = interval/60;                  /* 计算完整分钟数表示的通话时间*/
     if (interval % 60) c++,c+=1,c=c+1;
     fee += c * 0.08;
   }
   fclose(fin);
   printf("您好你本月的电话费用是：\n");
   printf("fee = %.2lf\n",fee);
   system("PAUSE");
}
//说明：dial.txt文本文件的内容，类似如下：
//o 14:05:23 14:11:25 82346789
//i 15:10:00 16:01:15 13890000000
//o 10:53:12 11:07:05 63000123
//o 23:01:12 00:12:15 13356789001
