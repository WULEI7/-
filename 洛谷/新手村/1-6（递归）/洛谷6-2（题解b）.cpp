#include <iostream>
#include <cstdio>
using namespace std;

bool isprime(int a){//�ж�����
    /*0��1�������ûɶ�ö�����
    �²ۣ�����n�����ݷ�Χ����֣�
    n���п���=1.....��k<n......
    */
    for(int i=2;i*i<=a;i++)//������sqrt����Ҫͷ�ļ�
        if(a%i==0)//�������
            return false;//�ӻ�false
    //���򶼵�����Ļ���˵����Ϊ����
    //����ͱ��ӻ���
    return true;//�ӻ�true
}

int n,k;
int a[25];
long long ans;

void dfs(int m,int sum,int startx){//����Ҫ�ĵݹ�
//m��������select�˶��ٸ���
//sum��ʾ��ǰ�ĺ�
//startx��ʾ�������У���������
    if(m==k){//���ѡ���˵Ļ�
        if(isprime(sum))//�����������
            ans++;//ans��һ
        return ;
    }
    for(int i=startx;i<n;i++)
        dfs(m+1,sum+a[i],i+1);//�ݹ�
        //����Ҫ��һ����ҲҪ��
        //������ʼֵҪ���i+1,��������
    return ;//��һ�������£����еĶ�ö������
    //ֱ�ӷ���ȥ
}

int main(){
    scanf("%d%d",&n,&k);//����

    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);//ѭ������
    dfs(0,0,0);//���ú���
    printf("%d\n",ans);//�����
    return 0;//��������
}
