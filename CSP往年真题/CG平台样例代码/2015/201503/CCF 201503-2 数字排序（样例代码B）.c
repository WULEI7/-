#include <stdio.h>
#define N 1010

int n;
int a[N] = {0};

int main()
{
    scanf("%d", &n);
    int num, l, r, i, j;
    scanf("%d", &num);
    l = r = num;
    a[num]++;
    for (i = 1; i < n; i++)
    {
        scanf("%d", &num);
        a[num]++;
        if (l > num)
            l = num;
        if (r < num)
            r = num;
    }
    int max_count, max_count_min_pos;
    max_count = max_count_min_pos = -1;
    for (i = 0; i < n; i++)
    {
        for (j = l; j <= r; j++)
        {
            if (max_count < a[j])
            {
                max_count = a[j];
                max_count_min_pos = j;
            }
        }
        if (a[max_count_min_pos])
        {
            printf("%d %d\n", max_count_min_pos, max_count);
            a[max_count_min_pos] = 0;
            max_count = max_count_min_pos = -1;
        }
    }

    return 0;
}
