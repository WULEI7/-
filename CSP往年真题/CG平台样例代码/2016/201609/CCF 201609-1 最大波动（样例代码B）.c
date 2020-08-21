#include <stdio.h>
#include <math.h>
int main(){
    int n, Fro, Nex, Del, Res = 0;
    scanf("%d%d", &n, &Fro); // 输入n,第一个数;
    while (--n) {
        scanf("%d", &Nex); // 循环输入第二至第n个数;
        Del = abs(Nex - Fro); // 保存波动值;
        Res = Del > Res ? Del : Res; // 保存最大波动值;
        Fro = Nex;
    }
    printf("%d\n", Res);
    return 0;
}

