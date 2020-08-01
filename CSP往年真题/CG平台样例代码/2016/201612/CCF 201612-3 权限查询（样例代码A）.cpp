#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef struct R{
    string name;
    map<string,int> priv;
}Role,User;

vector<Role> roleVec;
vector<User> userVec;

// pair<Ȩ��:�ȼ�>
pair<string,int> category(string str){
    int lev=-1;
    int len=str.length();
    if(len>=3&&str[len-2]==':'){
        lev=str[len-1]-'0';
        str=str.substr(0,len-2);
    }
    return pair<string,int>(str,lev);
}

int main(void){
    int n;
    string str;

    // ����Ȩ�޶���
    // ��Ϊ����������֤�Ϸ������ò���
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>str;
    }

    // �����ɫ����
    cin>>n;
    int nn;
    for(int i=0;i<n;i++){
        Role role;
        cin>>role.name>>nn;
        map<string,int> &refPriv=role.priv;
        for(int j=0;j<nn;j++){
            cin>>str;
            pair<string,int> t_pair=category(str);
            // ���Ȩ���ظ�,ȡ���ֵ
            map<string,int>::iterator it=refPriv.find(t_pair.first);
            if(it!=refPriv.end()){
                it->second=max(t_pair.second,it->second);
            }else{
                refPriv.insert(t_pair);
            }
        }
        roleVec.push_back(role);
    }

    // �����û�����
    cin>>n;
    for(int i=0;i<n;i++){
        User user;
        cin>>user.name>>nn;
        map<string,int> &usrPriv=user.priv;
        for(int j=0;j<nn;j++){
            cin>>str;
            int len=roleVec.size();
            int k;
            // ��ѯ��ɫ�Ƿ����
            for(k=0;k<len;k++){
                if(roleVec[k].name==str){
                    break;
                }
            }
            // ��ɫ����,��ӽ�ɫ�µ�ȫ��Ȩ��
            if(k!=len){
                map<string,int> &rolePriv=roleVec[k].priv;
                for(map<string,int>::iterator it=rolePriv.begin();it!=rolePriv.end();++it){
                    // Ȩ���ظ���ȡ���ֵ
                    map<string,int>::iterator usr_it=usrPriv.find(it->first);
                    if(usr_it!=usrPriv.end()){
                        usr_it->second=max(usr_it->second,it->second);
                    }else{
                        usrPriv.insert(pair<string,int>(it->first,it->second));
                    }
                }
            }
        }
        userVec.push_back(user);
    }

    // ��ѯ
    cin>>n;
    string name;
    for(int i=0;i<n;i++){
        cin>>name>>str;
        int len=userVec.size();
        int j;
        // �û��Ƿ����
        for(j=0;j<len;j++){
            if(userVec[j].name==name){
                break;
            }
        }
        // �û�����
        if(j!=len){
            map<string,int> &priv=userVec[j].priv;
            pair<string,int> cgy=category(str);
            // �û��ǲ��Ǵ������Ȩ��
            map<string,int>::iterator it=priv.find(cgy.first);
            // Ȩ�޴���
            if(it!=priv.end()){
                // �����ȼ��Ĳ�ѯ
                if(cgy.second==-1){
                    if(it->second==-1){ // Ȩ�޾��ǲ����ȼ���
                        cout<<"true"<<endl;
                    }else{  // Ȩ�޴��ȼ�
                        cout<<it->second<<endl;
                    }
                }else{  // ���ȼ���ѯ
                    if(cgy.second<=it->second){
                        cout<<"true"<<endl;
                    }else{
                        cout<<"false"<<endl;
                    }
                }
            }else{  // �û�û�����Ȩ��
                cout<<"false"<<endl;
            }

        }else{  // û������û�
            cout<<"false"<<endl;
        }
    }

    return 0;
}


