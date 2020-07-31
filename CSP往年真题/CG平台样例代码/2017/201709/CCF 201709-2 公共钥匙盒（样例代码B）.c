#include <stdio.h>
#include <stdlib.h>

#define maxn 1000 + 10

int keyDisk[maxn];

struct Ope {
	int w, t;
	int isGet;//1表示该操作为取操作，0表示该操作为还操作
}opes[2 * maxn];

typedef struct Ope Ope;

int cmp(const void* aa, const void* bb) {
	Ope* a = (Ope*)aa;
	Ope* b = (Ope*)bb;
	if ((*a).t == (*b).t) {
		if ((*a).isGet == (*b).isGet) {
			return (*a).w - (*b).w;
		}
		return (*a).isGet - (*b).isGet;
	}
	return (*a).t - (*b).t;
}
int main()
{
	int N, K, i, j, w, s, c;
	scanf("%d%d", &N, &K);
	for (i = 1; i <= N; ++i) {
		keyDisk[i] = i;
	}
	for (i = 0; i < K; ++i) {
		scanf("%d%d%d", &w, &s, &c);
		opes[i << 1].isGet = 1;
		opes[i << 1].w = w;
		opes[i << 1].t = s;
		opes[i << 1 | 1].isGet = 0;
		opes[i << 1 | 1].w = w;
		opes[i << 1 | 1].t = s + c;
	}
	qsort(opes, 2 * K, sizeof(Ope), cmp);
	for (i = 0; i < 2 * K; ++i) {
		if (opes[i].isGet) {
			for (j = 1; j <= N; ++j) {
				if (keyDisk[j] == opes[i].w) {
					keyDisk[j] = 0;
					break;
				}
			}
		}
		else {
			for (j = 1; j <= N; ++j) {
				if (keyDisk[j] == 0) {
					keyDisk[j] = opes[i].w;
					break;
				}
			}
		}
	}
	for (i = 1; i <= N; ++i) {
		printf("%d", keyDisk[i]);
		if (i != N) {
			printf(" ");
		}
	}
	printf("\n");
	return 0;
}
