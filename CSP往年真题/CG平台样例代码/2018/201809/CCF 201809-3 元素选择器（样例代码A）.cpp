#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN=105;

struct Selector{
    int row;
    int rank;
    string label;
    string id;
};

int n,m;
Selector sel[MAXN];
string html, css;

int main(){
    scanf("%d%d",&n,&m);
    getchar();
    for(int i=1;i<=n;i++){
        getline(cin,html);
        sel[i].row=i;
        
        istringstream ss(html);
        string str;
        
        ss>>str;
        int cd;
        for(cd=0;str[cd]=='.';cd++);
        sel[i].rank=cd/2; //����㼶
        sel[i].label=str.substr(cd); //��ȡ��ǩ
        transform(sel[i].label.begin(), sel[i].label.end(), sel[i].label.begin(), ::tolower); //ת��Сд
        
        while(ss>>str){ //��ȡid����
            if(str[0]=='#') sel[i].id=str;
        }
    }

    for(int i=0;i<m;i++){
        getline(cin,css);
        istringstream ss(css);
        vector<string> query;
        string str;
        while(ss>>str){ //�洢��ѯ����
            if(str[0]!='#'){
                transform(str.begin(),str.end(),str.begin(), ::tolower);
            }
            query.push_back(str);
        }
        
        //��ѯ���������һ����ǩ�������ǹؼ���
        
        int ans[MAXN]; //�洢��������������
        int cnt=0; //����
        int num; //ʵ�����������ĸ���
        vector<string>::reverse_iterator it=query.rbegin();
        for(int j=1;j<=n;j++){
            if(sel[j].id==*it || sel[j].label==*it){
                ans[cnt++]=j;
            }
        }
        num=cnt;
        
        for(int c=0;c<cnt;c++){ //����ÿ���ؼ��֣��ж��Ƿ���������
            it=query.rbegin()+1;
            int mrank=sel[ans[c]].rank;
            for(int j=ans[c]-1;it!=query.rend() && j>0;j--){
                if(sel[j].rank<mrank && (*it==sel[j].label || *it==sel[j].id)){
                    it++;
                    mrank=sel[j].rank;
                }
            }
            if(it!=query.rend()){
                ans[c]=0;
                num--;
            }
        }
        
        cout<<num;
        for(int j=0;j<cnt;j++){
            if(ans[j]){
                cout<<" "<<ans[j];
            }
        }
        cout<<endl;
    }
    return 0;
}


