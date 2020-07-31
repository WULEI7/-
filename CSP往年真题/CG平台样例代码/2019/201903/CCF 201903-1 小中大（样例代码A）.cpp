#include<cstdio>
const int MAXN=100010;

int n;
int arr[MAXN];

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    
    int mx, mn;
    double mid;
    if(arr[0]<=arr[n-1]){
        mx=arr[n-1];
        mn=arr[0];
    }
    else{
        mx=arr[0];
        mn=arr[n-1];
    }
    
    if(n&1){ //奇数
        mid=arr[n/2];
        printf("%d %d %d\n",mx, (int)mid, mn);
    }
    else{ //偶数
        mid=(arr[n/2-1]+arr[n/2])*1.0/2;
        if((mid-(int)mid)==0){ //整数
            printf("%d %d %d\n", mx,(int)mid, mn);
        }
        else{
            printf("%d %.1f %d\n",mx,mid,mn);
        }
    }
    
    return 0;
}


