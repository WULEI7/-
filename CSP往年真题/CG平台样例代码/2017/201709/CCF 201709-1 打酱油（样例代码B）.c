#include <stdio.h>

int main()
{
	int money;
	int num = 0;
	scanf("%d", &money);
	num += money / 50 * 7;
	money %= 50;
	num += money / 30 * 4;
	money %= 30;
	num += money / 10 * 1;
	printf("%d\n", num);
	return 0;
}

