#include<stdio.h>
#include <algorithm>
using namespace std;
int findx(int a[],int left,int right,int x){
	int mid;
	while(left<=right){
		mid=(left+right)/2;
		if(a[mid]==x){
			return mid;
		}
		else if(a[mid]>x){
			right=mid-1;
		}
		else{
			left=mid+1;
		}
	} 
	return -1;
}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		int num[110];
		for(int i=0;i<n;i++){
			scanf("%d",&num[i]);
		}
		sort(num,num+n);
		int m;
		scanf("%d",&m);
		int t[110];
		for(int i=0;i<m;i++){
			scanf("%d",&t[i]);
		}
		for(int i=0;i<m;i++){
			int b=findx(num,0,n-1,t[i]);
			if(b!=-1){
				printf("YES\n");
			}
			else{
				printf("NO\n");
			}
		}
	}
	return 0;
}
