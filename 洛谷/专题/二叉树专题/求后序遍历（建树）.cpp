#include <iostream>
#include<string.h>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
typedef struct node
{
    int  data;
    struct node *l,*r;
}node,*bitree;
void build(bitree &t,int *pre,int *ord,int n)
{
    t=new node;
    t->data=pre[0];
    int i,k;
    if(n==0)
    {
    t=NULL;
        return ;
    }

//a�������� ������������ b������
    int  a[1010],b[1010];
    i=0;
    while(pre[0]!=ord[i])
    {
       a[i]=pre[i+1];
       b[i]=ord[i];
       i++;
    }
    build(t->l,a,b,i);//�ݹ齨��������

////c�������� ������������ d������
    int  c[1010],d[1010];
    int j=0;
    for(k=i+1;k<n;k++)
    {
        c[j]=pre[k];
        d[j]=ord[k];
        j++;
    }


    build(t->r,c,d,j);//�ݹ齨��������
}
int q=1;
void pr(bitree t)
{
    if(t==NULL ) return ;
    if(t->l) pr(t->l);
    if(t->r)pr(t->r);if(q==1){cout<<t->data;q=0;} 
    else
    cout<<" "<<t->data;
}
int pre[1010],ord[1010];
int main()
{
    int n;
    while(cin>>n)
    {
        bitree t;
        for(int i=0;i<n;i++)
        {
            cin>>pre[i];
        }
        for(int i=0;i<n;i++)
            cin>>ord[i];
        build(t,pre,ord,n);
        q=1;
        pr(t);
        cout<<endl;
    }
    return 0;
}
