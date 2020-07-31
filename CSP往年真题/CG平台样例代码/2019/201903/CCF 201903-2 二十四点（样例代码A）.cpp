/* CCF201903-2 二十四点 */

#include <stdio.h>

/* 判定24点函数 */
int judge(char s[])
{
    int a[4], i, j;
    char op[3];

    /* 从输入取出数和运算符 */
    for(i = 0; i < 4; i++)
        a[i] = s[i * 2] - '0';
    for(i = 0; i < 3; i++)
        op[i] = s[i * 2 + 1];

    int k = 3;  /* 总共计算3次 */
    /* 先计算乘(x)和除(/) */
    for(i = 0; i < k; i++)
        if(op[i] == 'x' || op[i] == '/') {
            if(op[i] == 'x') a[i] = a[i] * a[i + 1];
            else a[i] = a[i] / a[i + 1];
            for(j = i + 1; j < k; j++) {
                op[j - 1] = op[j];
                a[j] = a[j + 1];
            }
            k--, i--;
        }
    /* 再计算加(+)和减(-) */
    int ans = a[0];
    for(i = 0; i < k; i++)
        if(op[i] == '+') {
            ans = a[i] + a[i + 1];
            a[i + 1] = ans;
        } else {
            ans = a[i] - a[i + 1];
            a[i + 1] = ans;
        }

    return ans == 24;
}

int main(void)
{
    int n;
    char s[7 + 1];
    scanf("%d", &n);
    while(n--) {
        scanf("%s", s);

        printf(judge(s) ? "Yes\n" : "No\n");
    }

    return 0;
}

