#include <stdio.h>

#define maxn 1000 + 10

int isOut[maxn];

int main()
{
	int n, k, i;
	int count = 0, outNum = 0;
	scanf("%d%d", &n, &k);
	for (i = 1; outNum != n - 1; ++i) {
		// i ���� n ʱ���ӵ�1��С���ѿ�ʼ���±���
		if (i == n + 1) {
			i = 1;
		}
		//���ѱ���̭��������
		if (isOut[i]) {
			continue;
		}
		//����
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
