#include<cstdio>

int N, M;
int T, k, P;

int main(){
    int d; //输入疏果个数
    int maxd=0; //最大疏果个数
    scanf("%d%d", &N, &M);
    for(int i=0; i<N; i++){
        P=0;
        
        scanf("%d", &d); //第一轮开始前的苹果个数
        T+=d;
        for(int j=1; j<=M; j++){
            scanf("%d", &d);
            T+=d;
            P-=d;
        }
        
        if(P>maxd){
            maxd=P;
            k=i+1;
        }
    }
    printf("%d %d %d\n", T, k, maxd);
    return 0;
}

