#include <iostream>  
#include <queue>  
using namespace std;  
int main() {  
    int n=0,k=0,i=0,num=1;  
    cin>>n>>k;  
    queue<int, deque<int> > q; //����һ�����������汨��  
    for(i=1;i<=n;i++) { //��ʼ������  
        q.push(i);  
    }  
    while(q.size()>1) { //�ж϶����Ƿ�ֻʣ��һ��Ԫ��  
        int top = q.front(); //���浱ǰ���׵�Ԫ��  
        q.pop();    //����ǰ����Ԫ��ֵ�Ӷ�����ɾ��  
        if(num%k!=0 && num%10!=k) { //�ж���ǰ�ı����Ƿ�������Ϸ����  
            q.push(top);    //�����㣬�򽫶������²����β���ȴ���һ����Ϸ  
        }  
        num++;  //����+1  
    }  
    cout<<q.front();    //�������q�н�ʣ��һ��Ԫ��  
    return 0;  
}

