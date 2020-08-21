#include<stdio.h>
int main() {
    int tic[105] = { 0 }, flag = 0;
    int temp = 0, n, p, i, j, t;
    scanf("%d", &n);
    for (t = 1; t <= n; t++) {
        scanf("%d", &p); flag = temp = 0;
        for (i = 1; i <= 100; i++) {
            if (tic[i] == 0) temp++; // 计数,看是否满足连票;
            if (temp == p) { // 满足连票;
                for (j = i - p + 1; j <= i; j++) {
                    tic[j] = 1; printf("%d", j);
                    if (j != i) printf(" ");
                }
                flag++;
                break;
            }
            if (i % 5 == 0) temp = 0;
            if (i == 100 && !flag) { // 插入座位;
                for (j = 1; j <= 100; j++) {
                    if (tic[j] == 0) {
                        tic[j] = 1; printf("%d", j);
                        temp++;
                        if (temp != p) printf(" ");
                    }
                    if (temp == p) break;
                }
            }
        }
        printf("\n");
    }
    return 0;
}


