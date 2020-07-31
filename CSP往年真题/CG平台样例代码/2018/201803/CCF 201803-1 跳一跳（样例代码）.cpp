#include<stdio.h>
int main(){
    int pre=0,cur;
    int ans=0;
    while(~scanf("%d",&cur) && cur){
        if(cur==1){
            ans+=1;
            pre=1;
        }
        else if(pre==1 || pre==0){
            ans+=2;
            pre=2;
        }
        else{
            ans+=pre+2;
            pre=pre+2;
        }
    }
    printf("%d\n",ans);
    return 0;
}


