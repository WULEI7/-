#include<stdio.h>
#include<math.h>
int main(){
	int a[3],b[3],n,i,k,t;
	scanf("%d", &n); 
	k=9999999999;
	for (i=0;i<3;i++){
		scanf("%d %d",&a[i],&b[i]);
		t = ceil(1.0*n/a[i])*b[i];
		if (t<k)
			k=t;
	}
	printf("%d",k);
	return 0;
} 
