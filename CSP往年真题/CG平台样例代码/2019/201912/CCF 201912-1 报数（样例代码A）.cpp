#include<cstdio>

int n;
int skip[4];

bool judge(int n){ //判断是否包含7
    int t=0;
    while(n && t!=7){
        t=n%10;
        n/=10;
    }
    if(t==7) return true;
    return false;
}

int main(){
    scanf("%d", &n);
    int turn=0; //轮到谁：0 1 2 3
    int cnt=0; //数了多少数，不包含跳过的数
    int i=1;
    while(cnt<n){
        if(i%7==0 || judge(i)){
            skip[turn]++;
        }
        else cnt++;
        turn=(turn+1)%4;
        i++;
    }
    
    for(int i=0;i<4;++i){
        printf("%d\n", skip[i]);
    }
    
    return 0;
}

