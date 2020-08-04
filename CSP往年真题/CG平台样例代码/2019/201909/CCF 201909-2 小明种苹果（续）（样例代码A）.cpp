#include<cstdio>

const int MAXN=1002;
bool has[MAXN]; //has[i]==true，第i+1棵树上有掉落

int N;
int T, D, E;

int main() {
    int m; //操作个数
    int d; //操作记录
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        scanf("%d", &m);
        int s=0; //第i棵树上的苹果总数
        scanf("%d", &s);
        T+=s;
        for(int j=1;j<m;j++){
            scanf("%d", &d);
            if(d<0){
                s+=d;
                T+=d;
            }
            if(d>0){
                if(s>d && has[i]==false){  //有掉落，且之前未发生过掉落
                    has[i]=true;
                    D++;
                }
                T-=(s-d);
                s=d; //重新统计该树上的苹果总数
            }
        }
    }
    //统计组数
    for(int i=0;i<N;i++){
        if(has[i] && has[(i+1)%N] && has[(i+2)%N]) E++;
    }
    printf("%d %d %d\n", T, D, E);
    
    return 0;
}

