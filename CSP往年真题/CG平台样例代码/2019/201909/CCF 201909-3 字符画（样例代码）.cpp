#include<iostream>
#include<iomanip>
#define OPT __attribute__((optimize("O3")))
using namespace std;
const int N=2e3;
short c[N][N][3];//c[n][m][Pixel:RGB] 表示原图片在第n行m列的像素颜色
int m,n,p,q,PQ,R,G,B,r,g,b,num[10];string s;
OPT inline short getCell(const char &a,const char &b){//将16进制像素数转换为10进制的char
    return (isalpha(a)?(10+a-'a'):(a-'0'))*16+(isalpha(b)?(10+b-'a'):(b-'0'));
}
OPT inline void outChar(const char &ch){//输出题意格式化的字符
    cout<<"\\x"<<hex<<uppercase<<setw(2)<<int(ch);
}
OPT inline void outStr(const string &str){//输出题意格式化的字符串
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
            switch(len){//统一格式标准化为 #abcdef
                case 2:s=s+string(5,s[1]);break;
                case 4:s="#"+string(2,s[1])+string(2,s[2])+string(2,s[3]);break;
            }
            for(int k=0;k<3;k++) c[i][j][k]=getCell(tolower(s[k*2+1]),tolower(s[k*2+2]));
        }
    }
    for(int i=1;i<=n;i+=q){//共n/q个字符块行
        for(int j=1;j<=m;j+=p){//每字符块行共m/p段
            R=G=B=0;//以下处理属于i行j段的字符块
            for(int k=i,ke=k+q;k<ke;k++)
                for(int l=j,le=j+p;l<le;l++)
                    R+=c[k][l][0],G+=c[k][l][1],B+=c[k][l][2];
            R/=PQ,G/=PQ,B/=PQ;//求平均值
            if(R!=r||G!=g||B!=b){//如果与该行上一段的颜色不同
                if(!R&&!G&&!B)//如果与默认值相同
                    outStr(string(1,char(27))+"[0m");
                else//其他颜色处理
                    outStr(string(1,char(27))+"[48;2;"),outCell(R),outChar(';'),outCell(G),outChar(';'),outCell(B),outChar('m');
                r=R,g=G,b=B;//记录上次的颜色
            }
            outChar(' ');//输出 (n*m)/(p*q) 个空格
        }
        if(R||G||B) outStr(string(1,char(27))+"[0m");//行尾判断是否需要重置颜色
        r=g=b=0;//重置默认颜色
        outChar('\n');//输出n/q个回车
    }
    return 0;
}


