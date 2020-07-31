#include <stdio.h>

#define maxn 1000 + 10

int isOut[maxn];

int main()
{
	int n, k, i;
	int count = 0, outNum = 0;
	scanf("%d%d", &n, &k);
	for (i = 1; outNum != n - 1; ++i) {
		// i 超过 n 时，从第1个小朋友开始重新遍历
		if (i == n + 1) {
			i = 1;
		}
		//若已被淘汰，则跳过
		if (isOut[i]) {
			continue;
		}
		//报数
		count++;
		if (count % k == 0 || count % 10 == k) {
			isOut[i] = 1;
			outNum++;
		}
	}
	for (i = 1; i <= n; ++i) {
		if (!isOut[i]) {
			printf("%d\n", i);
			break;
		}
	}
	return 0;
}
