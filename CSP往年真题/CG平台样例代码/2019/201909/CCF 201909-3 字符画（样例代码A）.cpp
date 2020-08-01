#include<iostream>
#include<iomanip>
#define OPT __attribute__((optimize("O3")))
using namespace std;
const int N=2e3;
short c[N][N][3];//c[n][m][Pixel:RGB] ��ʾԭͼƬ�ڵ�n��m�е�������ɫ
int m,n,p,q,PQ,R,G,B,r,g,b,num[10];string s;
OPT inline short getCell(const char &a,const char &b){//��16����������ת��Ϊ10���Ƶ�char
    return (isalpha(a)?(10+a-'a'):(a-'0'))*16+(isalpha(b)?(10+b-'a'):(b-'0'));
}
OPT inline void outChar(const char &ch){//��������ʽ�����ַ�
    cout<<"\\x"<<hex<<uppercase<<setw(2)<<int(ch);
}
OPT inline void outStr(const string &str){//��������ʽ�����ַ���
    for(const char &ch:str) outChar(ch);
}
inline void outCell(int x){
    int cnt(0);
    if(!x) num[++cnt]=0;
    for(;x;x/=10) num[++cnt]=x%10;
    for(int i=cnt;i;i--) outChar(char(num[i]+'0'));
}
OPT int main(){
    ios::sync_with_stdio(false);
    cin>>m>>n>>p>>q,PQ=p*q,cout.fill('0');
    for(int i=1;i<=n;i++){
        for(int j=1,len;j<=m;j++){
            cin>>s;len=s.length();
            switch(len){//ͳһ��ʽ��׼��Ϊ #abcdef
                case 2:s=s+string(5,s[1]);break;
                case 4:s="#"+string(2,s[1])+string(2,s[2])+string(2,s[3]);break;
            }
            for(int k=0;k<3;k++) c[i][j][k]=getCell(tolower(s[k*2+1]),tolower(s[k*2+2]));
        }
    }
    for(int i=1;i<=n;i+=q){//��n/q���ַ�����
        for(int j=1;j<=m;j+=p){//ÿ�ַ����й�m/p��
            R=G=B=0;//���´�������i��j�ε��ַ���
            for(int k=i,ke=k+q;k<ke;k++)
                for(int l=j,le=j+p;l<le;l++)
                    R+=c[k][l][0],G+=c[k][l][1],B+=c[k][l][2];
            R/=PQ,G/=PQ,B/=PQ;//��ƽ��ֵ
            if(R!=r||G!=g||B!=b){//����������һ�ε���ɫ��ͬ
                if(!R&&!G&&!B)//�����Ĭ��ֵ��ͬ
                    outStr(string(1,char(27))+"[0m");
                else//������ɫ����
                    outStr(string(1,char(27))+"[48;2;"),outCell(R),outChar(';'),outCell(G),outChar(';'),outCell(B),outChar('m');
                r=R,g=G,b=B;//��¼�ϴε���ɫ
            }
            outChar(' ');//��� (n*m)/(p*q) ���ո�
        }
        if(R||G||B) outStr(string(1,char(27))+"[0m");//��β�ж��Ƿ���Ҫ������ɫ
        r=g=b=0;//����Ĭ����ɫ
        outChar('\n');//���n/q���س�
    }
    return 0;
}


