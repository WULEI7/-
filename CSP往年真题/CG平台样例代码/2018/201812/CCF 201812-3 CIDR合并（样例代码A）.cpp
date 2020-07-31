#include<stdio.h>
#include<string.h>
#include<algorithm>
typedef unsigned int UI;
const int N=1e5+5;
struct IP{UI val,a[5];}ip[N];//a[0]~a[3]��ʾIP��ַ,a[4]��ʾ��Ŀ�е�len
//val��ʾIP��ַ��ʮ������ʽ����Ҫ���ã�IPǰ׺�ܱ�ʾ����ֵ��Χ��
char str[33];int n;
void dealStr(int id){//�ַ����������,ת���ɱ�׼��
    scanf("%s",str);
    int cnt(0),pn(0),xn(0),len=strlen(str);//pn���������snб�ܵ�����
    for(int i=0;i<len;i++){
        if(str[i]=='.') pn++;else
        if(str[i]=='/') xn++;
    }
    for(int i=0;i<5;i++) ip[id].a[i]=0;
    char *p1=str,*p2,tmp[6];
    for(int i=0;i<pn;i++){
        p2=strchr(p1,'.');
        strncpy(tmp,p1,p2-p1);//strncpy���ƴ�p1��p2-p1���ȵ��ַ�����tmp��
        tmp[p2-p1]=0;
        ip[id].a[cnt++]=atoi(tmp);
        p1=p2+1;
    }
    if(xn){
        p2=strchr(p1,'/');//strchr��p1�в��ҡ�/����һ�γ��ֵ�λ��
        strncpy(tmp,p1,p2-p1);
        tmp[p2-p1]=0;
        ip[id].a[cnt++]=atoi(tmp);//atoi �ַ���ת����
        p1=p2+1;
        strcpy(tmp,p1);
        ip[id].a[4]=atoi(tmp);
    }
    else{
        strcpy(tmp,p1);
        ip[id].a[cnt++]=atoi(tmp);
        ip[id].a[4]=cnt*8;
    }
    ip[id].val=0;//����ipʮ����ֵ
    for(int i=0;i<4;i++) ip[id].val+=ip[id].a[i]<<8*(3-i);
}
inline bool cmp(const IP &ip1, const IP &ip2){
    for(int i=0;i<5;i++) if(ip1.a[i]!=ip2.a[i]) return ip1.a[i]<ip2.a[i];
    return 0;
}
inline void range(IP &ip0,UI &l,UI &r){//����IPǰ׺�ܱ�ʾ����ֵ��Χ
    UI len=32-ip0.a[4];
    l=ip0.val>>len<<len;
    r=ip0.val|((1<<len)-1);
}
void union1(){//��С����ϲ�
    int p=0;
    UI la,lb,ra,rb;
    for(int i=1;i<n;i++){
        range(ip[p],la,ra);
        range(ip[i],lb,rb);
        if(la>lb||rb>ra) ip[++p]=ip[i];
    }
    n=p+1;
}
inline bool judgeUnion(IP &ip1,IP &ip2,IP &res){//�ж�ͬ���ܷ�ϲ�
    if(ip1.a[4]!=ip2.a[4]||ip1.a[4]<1) return 0;
    res=ip1;res.a[4]--;
    UI la,lb,lc,ra,rb,rc;
    range(ip1,la,ra);
    range(ip2,lb,rb);
    range(res,lc,rc);
    if(la==lc&&rb==rc&&lb<=ra+1) return 1;
    return 0;
}
void union2(){
    int p=0;IP res;
    for(int i=1;i<n;i++){
        if(judgeUnion(ip[p],ip[i],res)){
            ip[p]=res;
            while(p>0&&judgeUnion(ip[p-1],ip[p],res)) ip[--p]=res;
        }
        else{
            ip[++p]=ip[i];
        }
    }
    n=p+1;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) dealStr(i);
    std::sort(ip,ip+n,cmp);
    union1();
    union2();
    for(int i=0;i<n;i++) printf("%u.%u.%u.%u/%u\n",ip[i].a[0],ip[i].a[1],ip[i].a[2],ip[i].a[3],ip[i].a[4]);
    return 0;
}

