#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#define N 1005
#define MAXL 81925

int n; //�����е�Ӳ����Ŀ
int s; //������С����λ���飬1����4�ֽڣ�
int l; //�ִ��Ӳ����Ŀ
int m; //����������
int b; //���ţ���0������
char disk[N][MAXL];
int len; //���������ַ�������

int char2digit(char c){ //ʮ�������ַ�ת����
    if(isdigit(c)) return c-'0';
    return c-'A'+10;
}

char digit2char(int d){ //����תʮ�������ַ�
    if(d<10) return '0'+d;
    return 'A'+d-10;
}

void calXor(char *a, char *b){ //����a^b
    for(int i=0;i<8;i++){
        a[i]=digit2char(char2digit(a[i])^char2digit(b[i]));
    }
}

char* substr(char *s ,int n){ //���ش�s�𳤶�Ϊn���ַ���
    char *sp=(char*)malloc(sizeof(char)*(n+1));
    for(int i=0; i<n; ++i) sp[i]=s[i];
    sp[n]=0;
    return sp;
}

int main(){
    scanf("%d%d%d",&n, &s, &l);
    //���������Ϣ
    int index=0; //Ӳ��˳���
    for(int i=0; i<l; ++i){
        scanf("%d%*c", &index);
        fgets(disk[index],MAXL,stdin); //���ڳ��ַ���������ֱ��ʹ��scanf��cin������ʱ
    }
    len=strlen(disk[index]);
    
    //��������
    scanf("%d", &m);
    for(int i=0;i<m;++i){
        scanf("%d",&b);
        int diskId=b%(n*s)/s; //�̺�
        int lineId=b/((n-1)*s)*s+b%s; //�к�
        if((lineId+1)*8>len || (disk[diskId][0]=='\0' && l<n-1)){ //��ų������̴�С��ʧ���̶���1
            printf("-\n");
        }
        else if(disk[diskId][0]!='\0'){//b�������̴���
            printf("%s\n", substr(disk[diskId]+lineId*8, 8));
        }
        else{    //b�������̶�ʧ�������Ի�ԭ
            char ans[10]="00000000";
            for(int j=0;j<n;++j){
                if(j!=diskId) calXor(ans, substr(disk[j]+lineId*8, 8));
            }
            printf("%s\n",ans);
        }
    }
    return 0;
}

