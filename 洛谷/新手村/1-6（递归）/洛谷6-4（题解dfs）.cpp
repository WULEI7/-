#include<iostream>
using namespace std;
bool isprime(int x){ //�ж������ĺ�����Ӧ�ò����Ҷ����
    if(x<2)return false;
    if(x==2)return true;
    for(int i=2;i*i<=x;i++){
        if(x%i==0)return false;
    }
    return true;
}
int l,r,x,y; //l,r����Ŀ��Χ��x,y�����ǵĳ���
int a[10];  //���洴���������
bool b=true;  //������Ϊ�Ƿ��������ж�
void go(int x,int k){  //k����λ����x��Ŀǰö�ٵ���λ��
    if(x==(k+1)/2){  //(k+1)/2��kλ���м����������Լ���һ��
        for(int i=k;i>x;i--){  //��ʣ�µ�λ������
            a[i]=a[k-i+1];
        }
        int shu=0;  //������ת������
        for(int i=1;i<=k;i++){
            shu=shu*10+a[i];
        }
        if(shu<l)return; //С��l������
        if(shu>r){ //����r������
            b=false;
            return;
        }
        if(isprime(shu))cout<<shu<<endl; //�����������
        return; //���һ������©��Ҫ��Ȼ��һֱ����ȥ��������������������ܺ��ߣ�
    }
    int i;
    if(x)i=0;
    else i=1; //���λ������0
    for(i=i;i<=9;i++){ //dfs(�����������)��һλ��ûѧ������ȥ����P1706
        if(b==false)return; //����Ѿ����ִ���r����������������
        a[x+1]=i;
        go(x+1,k);
    }
    return;
}
int weishu(int j){ //����һ�����ĳ���
    int b=j,count=0;
    while(b>0){
        b/=10;
        count++;
    }
    return count;
}
int main(){
    cin>>l>>r;
    x=weishu(l);
    y=weishu(r);
    for(int i=x;i<=y;i++){
        if(i==1){ //һλ������
            if(l<=5&&r>=5)cout<<5<<endl;
            if(l<=7&&r>=7)cout<<7<<endl;
            continue;
        }
        if(i==2){ //��λ������
            if(l<=11&&r>=11)cout<<11<<endl;
            continue;
        }
        if(i%2==0)continue; //ż��λ������
        if(i==9)break; //��λֱ������
        b=true; //ÿ������Ҫ�������������
        go(0,i); //�ӵ�0λ��ʼ��
    }
    return 0;
}
