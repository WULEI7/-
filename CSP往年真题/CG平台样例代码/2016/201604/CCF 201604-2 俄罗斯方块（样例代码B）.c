#include<stdio.h>
int main() {
    int a[20][15] = { 0 }, c[4][2] = { 0 }, left, temp, num = 0;
    for (int i = 1; i <= 15; i++)
        for (int j = 1; j <= 10; j++)
            scanf("%d", &a[i][j]);
    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 4; j++) {
            scanf("%d", &temp);
            if (temp) {
                c[num][0] = i; // 记录板块中的每个方块初始坐标;
                c[num++][1] = j;
            }
        }
    scanf("%d", &left);
    for (int i = 0; i < 4; i++)
        c[i][1] += left - 1; // 加上初始出现位置;
    while (1) { // 因为肯定有方块所以不会出现死循环的情况;
        for (int i = 0; i < 4; i++) if (a[c[i][0] + 1][c[i][1]] || c[i][0] == 15) { // 如果触底打印图像;
            for (int i = 0; i < 4; i++)
                a[c[i][0]][c[i][1]] = 1;
            for (int i = 1; i <= 15; i++) {
                for (int j = 1; j <= 10; j++) printf("%d ", a[i][j]);
                printf("\n");
            }
            return 0;
        }
        for (int i = 0; i < 4; i++) c[i][0]++; // 未触底板块整体向下移动;
    }
}

