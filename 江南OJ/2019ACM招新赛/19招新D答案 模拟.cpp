#include <bits/stdc++.h>
using namespace std;
const char *s1[20] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
const char *s2[10] = {"", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
void print2(int n)//输出两位数
{
        if (n < 20) {
                 printf("%s",s1[n]);
                 return;
        }
        printf("%s", s2[n / 10]);
        if (n % 10) printf(" %s", s1[n % 10]);
}
void print3(int n)//三位数
{
        if (n / 100) {
                 printf("%s hundred", s1[n / 100]);
                 if (n % 100) printf(" and ");
        }
        if (!n || n % 100) print2(n % 100);
}
void print(int n)
{
        if (n < 1000) print3(n);
        else {
                 print3(n / 1000);
                 printf(" thousand");
                 if (n % 1000)
                 {
                         putchar(' ');
                         if ((n / 100) % 10 == 0) printf("and ");
                         print3(n % 1000);
                 }
        }
}
int main()
{
        int n;
        scanf("%d", &n);
        print(n);
}
