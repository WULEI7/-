#include<cstdio>

const int MAXN=1002;
bool has[MAXN]; //has[i]==true����i+1�������е���

int N;
int T, D, E;

int main() {
    int m; //��������
    int d; //������¼
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        scanf("%d", &m);
        int s=0; //��i�����ϵ�ƻ������
        scanf("%d", &s);
        T+=s;
        for(int j=1;j<m;j++){
            scanf("%d", &d);
            if(d<0){
                s+=d;
                T+=d;
            }
            if(d>0){
                if(s>d && has[i]==false){  //�е��䣬��֮ǰδ����������
                    has[i]=true;
                    D++;
                }
                T-=(s-d);
                s=d; //����ͳ�Ƹ����ϵ�ƻ������
            }
        }
    }
    //ͳ������
    for(int i=0;i<N;i++){
        if(has[i] && has[(i+1)%N] && has[(i+2)%N]) E++;
    }
    printf("%d %d %d\n", T, D, E);
    
    return 0;
}

