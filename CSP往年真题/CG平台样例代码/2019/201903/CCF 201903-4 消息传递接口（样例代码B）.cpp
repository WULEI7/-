//ת�� https://blog.csdn.net/richenyunqi/article/details/89195878
#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("5.in","r",stdin);
	//freopen("5.out","w",stdout);
    int T,n;
    scanf("%d%d%*c",&T,&n);
    while(T--){
        list<pair<queue<int>,int>>process;//first��Ա��һ�����У��洢ÿ�����̵�����ָ�second��Ա�洢��һ��ִ�е�ָ���ʼ��ΪINT_MAX
        unordered_set<int>commands;//�洢ÿ����������ִ�е�ָ��
        string s;
        for(int i=0;i<n;++i){
            process.push_back({queue<int>(),INT_MAX});
            getline(cin,s);
            for(int j=0,k;j<s.size();j=k+1){//���ո���ָ��ַ���������������ʾָ��
                k=s.find(' ',j);
                if(k==string::npos)
                    k=s.size();
                if(s[j]=='S')
                    process.back().first.push(i*10000+stoi(s.substr(j+1,k-j-1)));
                else
                    process.back().first.push(-(stoi(s.substr(j+1,k-j-1))*10000+i));
            }
        }
        for(bool f=true;!process.empty();f=true){//f��־�Ƿ����н���ָ�������
            for(auto i=process.begin();i!=process.end();++i){//�������н���
                if(commands.find(i->second)!=commands.end())//��һ��ִ�е�ָ�������
                    continue;//����Ҳ������������ָ���޷�ִ��
                if((i->first).empty()){//����ָ�����ִ�����
                    i=process.erase(i);//���ý���ɾ��
                    --i;
                    continue;
                }
                while(!(i->first).empty()){//���̻���ָ��Ҫִ��
                    int t=(i->first).front();//�Ӷ��׵���һ��ָ��
                    (i->first).pop();
                    auto j=commands.find(-t);//���������������Ƿ�������ִ�еĶ�Ӧ��ָ��
                    if(j==commands.end()){//û�ж�Ӧ��ָ��
                        commands.insert(t);//����ָ����뵽commands��
                        i->second=t;//������һ��ִ�е�ָ��Ϊ��ǰָ��
                        break;
                    }else{//�ж�Ӧ��ָ��
                        commands.erase(j);//����Ӧ��ָ���commands��ɾ��
                        f=false;//���������н��̶�������
                    }
                }
            }
            if(f)//���������н��̺������н��̾���������˵����������
                break;
        }
        puts(process.empty()?"0":"1");//����ѭ��ʱ����listΪ�գ���ʾ���н���ָ���ִ����ϣ���û������
    }
    return 0;
}


