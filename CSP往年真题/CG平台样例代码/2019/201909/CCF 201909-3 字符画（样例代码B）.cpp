#include<iostream>
#include<cstring>
#define ll long long
using namespace std;
const int maxn=2050;
const int maxm=4e6+50;
int picture[maxn][maxn][3],tot=0;
char tmp[20];
string op1="\\x1B\\x5B\\x34\\x38\\x3B\\x32\\x3B",op2="\\x1B\\x5B\\x34\\x38\\x3B\\x32\\x3B",op3="\\x1B\\x5B\\x30\\x6D";
struct node{int r,g,b;}ans[maxm];
int trans(char ch)
{
    if(ch>='0'&&ch<='9')return ch-'0';
    if(ch>='a'&&ch<='f')return ch-'a'+10;
    if(ch>='A'&&ch<='F')return ch-'A'+10;
}
void init(){cout<<op3;}
void work(int x)
{
    //printf("\nx=%d\n",x);
    int ttmp[20],now=0;
    if(!x)ttmp[++now]=0;
    while(x){ttmp[++now]=x%10;x/=10;}
    for(int i=now;i>=1;i--)printf("\\x3%d",ttmp[i]);
}
void print(int now)
{
    cout<<op2;
    work(ans[now].r);printf("\\x3B");
    work(ans[now].g);printf("\\x3B");
    work(ans[now].b);printf("\\x6D");
}
int main()
{
	int n,m,p,q;scanf("%d%d%d%d",&m,&n,&p,&q);
	for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            scanf("%s",tmp);
            int len=strlen(tmp),num1,num2,num3;
            if(len==7)
            {
                num1=trans(tmp[1])*16+trans(tmp[2]);
                num2=trans(tmp[3])*16+trans(tmp[4]);
                num3=trans(tmp[5])*16+trans(tmp[6]);
            }
            else if(len==4)
            {
                num1=trans(tmp[1])*16+trans(tmp[1]);
                num2=trans(tmp[2])*16+trans(tmp[2]);
                num3=trans(tmp[3])*16+trans(tmp[3]);
            }
            else if(len==2)num1=num2=num3=trans(tmp[1])*16+trans(tmp[1]);
            picture[i][j][0]=num1;picture[i][j][1]=num2;picture[i][j][2]=num3;
            //cout<<endl<<picture[i][j][0]<<endl<<picture[i][j][1]<<endl<<picture[i][j][2]<<endl;
        }
    int R=n/q,C=m/p,sz=p*q;
    for(int i=1;i<=R;i++)
        for(int j=1;j<=C;j++)
        {
            int nowx=(i-1)*q+1,nowy=(j-1)*p+1,endx=i*q,endy=j*p,num1=0,num2=0,num3=0;
            //cout<<"nowx="<<nowx<<" nowy="<<nowy<<" endx="<<endx<<" endy="<<endy<<"\n";
            for(int ii=nowx;ii<=endx;ii++)
                for(int jj=nowy;jj<=endy;jj++)
                    num1+=picture[ii][jj][0],num2+=picture[ii][jj][1],num3+=picture[ii][jj][2];
            //cout<<"num1="<<num1<<" num2="<<num2<<" num3="<<num3<<"\n";
            num1/=sz;num2/=sz;num3/=sz;ans[++tot].r=num1;ans[tot].g=num2;ans[tot].b=num3;
        }
    int nr=0,ng=0,nb=0,cnt=0;
    for(int i=1;i<=tot;i++)
    {
        if(ans[i].r==nr&&ans[i].g==ng&&ans[i].b==nb);
        else if(ans[i].r==0&&ans[i].g==0&&ans[i].b==0)init();
        else print(i);
        nr=ans[i].r;ng=ans[i].g;nb=ans[i].b;printf("\\x20");cnt++;
        //cout<<"cnt="<<cnt<<"\n";
        if(cnt==C){cnt=0;if(nr||ng||nb){init();nr=ng=nb=0;}printf("\\x0A");}
    }
    return 0;
}

/*

ESC---\x1B
[---\x5B
(space)---\x20
0~9---\x(30~39)
;---\x3B
m---\x6D
\n---\x0A

1.
\x1B\x5B\x33\x38\x3B(R)\x3B(G)\x3B(B)\x6D
2.
\x1B\x5B\x34\x38\x3B\(R)\x3B(G)\x3B(B)\x6D
3.
\x1B\x5B\x30\x6D

*/
