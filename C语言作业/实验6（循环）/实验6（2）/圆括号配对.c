#include <stdio.h>
int main()
{
	int left,right;char c;
	printf("����һ���������ʽ\n");
	left=0;right=0;
	for(c=0;(c=getchar())!=10;){
		if(c=='(') left++;
		if(c==')') right++;
		if(left<right) break;
	}
	if(left==right) printf("Բ���������ȷ\n");
	else printf("Բ������Բ���ȷ\n");
	return 0; 
}
