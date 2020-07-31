#include<stdio.h>
int main(){
	int n,a[10005]={},s;
	int i,sum=0,v=0;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &s);
		a[s]++;
	} 
	for(i=0;i<=10000;i++){
		if(a[i]>sum){
			sum=a[i],v=i;
		}
	}
	printf("%d\n", v);
	return 0;
}

