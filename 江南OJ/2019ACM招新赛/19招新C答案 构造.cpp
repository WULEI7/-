#include <bits/stdc++.h>
using namespace std; 
const int maxn = 205;
int main()
{
        char ans[maxn];
        int a, b, x;
        scanf("%d%d%d", &a, &b, &x);
        if (a > b) {//先输出较多的 比如a=2 b=1 x=2的情况你如果先输出1就不可能凑够x了
                 ans[0] = '0';
                 a--;
        } else {
                 ans[0] = '1';
                 b--;
        }
        int i = 1;
        while (x > 1)//交替输出0和1来达到x的要求
        {//之所以要留1个x是因为可能0和1都有多的 如果x=0就不可能把剩下的0和1都输出而不增加x了
                 if (ans[i-1] == '0') {
                         ans[i] = '1';
                         b--;
                 } else {
                         ans[i] = '0';
                         a--;
                 }
                 x--;
                 i++;
        }
        if (ans[i - 1] == '1')//输出多出来的0和1
        {
                 while (b) {
                         ans[i++] = '1';
                         b--;
                 }
                 while (a) {
                         ans[i++] = '0';
                         a--;
                 }
        }
        else
        {
                 while (a) {
                         ans[i++] = '0';
                         a--;
                 }
                 while (b) {
                         ans[i++] = '1';
                         b--;
                 }
        }
        printf("%s\n",ans);
}
