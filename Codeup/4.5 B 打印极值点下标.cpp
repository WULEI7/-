#include<cstdio>
void findi(int a[],int n){
	int flag=0;
	if(a[0]!=a[1]){
		printf("0 ");
		flag=1;
	}
	for(int i=1;i<n-1;i++){
		int left=i-1;
		int right=i+1;
		if(a[i]>a[left]&&a[i]>a[right]){
			printf("%d ",i);
			flag=1;
		}
		else if(a[i]<a[left]&&a[i]<a[right]){
			printf("%d ",i);
			flag=1;
		}
	}
		if(a[n-1]!=a[n-2]){
			printf("%d",n-1);
			flag=1;
		}
	if(flag==1)
		printf("\n");
}

int main(){
	int m;
	while(scanf("%d",&m)!=EOF){
		while(m--){
			int n;
			scanf("%d",&n);
			int num[100];
			for(int i=0;i<n;i++){
				scanf("%d",&num[i]); 
			}
			findi(num,n);
		} 
	}
	return 0;
}
