#include <stdio.h>
#include <stdlib.h>

#define maxn 1000 + 10

int a[maxn];

int cmp(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}

int main()
{
	int n, i;
	int ans = 100000;
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	qsort(a, n, sizeof(int), cmp);
	for (i = 1; i < n; ++i) {
		if (a[i] - a[i - 1] < ans) {
			ans = a[i] - a[i - 1];
		}
	}
	printf("%d\n", ans);
	return 0;
}
