#include <stdio.h>
#include <math.h>
int main(){
    int n, Fro, Nex, Del, Res = 0;
    scanf("%d%d", &n, &Fro); // ����n,��һ����;
    while (--n) {
        scanf("%d", &Nex); // ѭ������ڶ�����n����;
        Del = abs(Nex - Fro); // ���沨��ֵ;
        Res = Del > Res ? Del : Res; // ������󲨶�ֵ;
        Fro = Nex;
    }
    printf("%d\n", Res);
    return 0;
}

