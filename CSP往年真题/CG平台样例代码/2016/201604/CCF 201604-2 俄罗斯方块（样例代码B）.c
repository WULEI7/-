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
                c[num][0] = i; // ��¼����е�ÿ�������ʼ����;
                c[num++][1] = j;
            }
        }
    scanf("%d", &left);
    for (int i = 0; i < 4; i++)
        c[i][1] += left - 1; // ���ϳ�ʼ����λ��;
    while (1) { // ��Ϊ�϶��з������Բ��������ѭ�������;
        for (int i = 0; i < 4; i++) if (a[c[i][0] + 1][c[i][1]] || c[i][0] == 15) { // ������״�ӡͼ��;
            for (int i = 0; i < 4; i++)
                a[c[i][0]][c[i][1]] = 1;
            for (int i = 1; i <= 15; i++) {
                for (int j = 1; j <= 10; j++) printf("%d ", a[i][j]);
                printf("\n");
            }
            return 0;
        }
        for (int i = 0; i < 4; i++) c[i][0]++; // δ���װ�����������ƶ�;
    }
}

