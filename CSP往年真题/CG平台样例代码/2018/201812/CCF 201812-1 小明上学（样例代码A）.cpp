#include<stdio.h>
#include<string.h>
#define MAXN 105
using namespace std;
int main(){
    int r,y,g;
    int n;
    int k,t;
    int ans=0;
    scanf("%d%d%d",&r,&y,&g);
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d",&k,&t);
        if(k==0) ans+=t;
        else if(k==1){
            ans+=t;
        }
        else if(k==2){
            ans+=t;
            ans+=r;
        }
    }
    printf("%d\n",ans);
    return 0;
}


