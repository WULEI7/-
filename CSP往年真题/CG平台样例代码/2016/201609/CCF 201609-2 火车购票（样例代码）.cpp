#include <iostream>
#include <queue>
using namespace std;
queue<int> mp[21];
int N;
int main(void){
    for(int i=1,j=1;i<=20;i++){ // ÿ����һ�����б�ʾ����һ��λ�õ���һ��Ԫ��
        mp[i].push(j++);
        mp[i].push(j++);
        mp[i].push(j++);
        mp[i].push(j++);
        mp[i].push(j++);
    }
    cin>>N;
    int num;
    for(int i=0;i<N;i++){
        cin>>num;
        bool ok=false;
        // ����������λ
        for(int row=1;row<=20;row++){
            if(mp[row].size()>=num){
                for(int j=0;j<num;j++){
                    cout<<mp[row].front()<<' ';
                    mp[row].pop();
                }
                ok=true;
                break;
            }
        }
        // ���ҷ�������λ
        if(!ok){
            for(int row=1;row<=20&&num>0;row++){
                while(num>0&&!mp[row].empty()){
                    cout<<mp[row].front()<<' ';
                    mp[row].pop();
                    num--;
                }
            }
        }
        cout<<endl;
    }
    return 0;
}


