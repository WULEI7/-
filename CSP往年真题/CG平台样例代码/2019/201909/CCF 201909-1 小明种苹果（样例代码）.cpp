#include<cstdio>

int N, M;
int T, k, P;

int main(){
    int d; //�����������
    int maxd=0; //����������
    scanf("%d%d", &N, &M);
    for(int i=0; i<N; i++){
        P=0;
        
        scanf("%d", &d); //��һ�ֿ�ʼǰ��ƻ������
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

