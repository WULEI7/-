#include <bits/stdc++.h>
using namespace std; 
const int maxn = 205;
int main()
{
        char ans[maxn];
        int a, b, x;
        scanf("%d%d%d", &a, &b, &x);
        if (a > b) {//������϶�� ����a=2 b=1 x=2���������������1�Ͳ����ܴչ�x��
                 ans[0] = '0';
                 a--;
        } else {
                 ans[0] = '1';
                 b--;
        }
        int i = 1;
        while (x > 1)//�������0��1���ﵽx��Ҫ��
        {//֮����Ҫ��1��x����Ϊ����0��1���ж�� ���x=0�Ͳ����ܰ�ʣ�µ�0��1�������������x��
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
        if (ans[i - 1] == '1')//����������0��1
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
