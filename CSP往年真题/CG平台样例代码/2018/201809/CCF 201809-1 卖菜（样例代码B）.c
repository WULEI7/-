#include<stdio.h>

int main(){
	int n,a[1005],b[1005],i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++){
		if(i==0)b[0]=(a[0]+a[1])/2;
		else if(i==n-1)b[n-1]=(a[n-2]+a[n-1])/2;
		else{
			b[i]=(a[i-1]+a[i]+a[i+1])/3;
		}
	}
	for(i=0;i<n;i++){
		printf("%d ",b[i]);
	}
	return 0;
}


