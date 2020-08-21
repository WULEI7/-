#include<stdio.h>
int main() {
    int n,t1,t2,t3,res =0;
    scanf("%d%d%d", &n,&t1,&t2);
    for (int i = 0; i < n-2; i++) {
        scanf("%d", &t3);
        if ((t1 > t2 && t3 > t2) || (t1 < t2 && t3 < t2)) res++;
        t1 = t2;
        t2 = t3;
    }
    printf("%d\n", res);
}

