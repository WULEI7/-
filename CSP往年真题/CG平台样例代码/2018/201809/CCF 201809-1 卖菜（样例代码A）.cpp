#include<stdio.h>
#define MAXN 1005
int arr[MAXN];
int ans[MAXN];
int n;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++){
        if(i==0){
            if(n>1) ans[i]=(arr[i]+arr[i+1])/2;
        }
        else if(i==n-1){
            if(n>1) ans[i]=(arr[i]+arr[i-1])/2;
        }
        else ans[i]=(arr[i-1]+arr[i]+arr[i+1])/3;
        printf("%d ",ans[i]);
    }
    return 0;
}


