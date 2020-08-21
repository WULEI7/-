#include<cstdio>
#include<cstring>
#include<set>
#include<vector>
using namespace std;

struct Goods{ //��Ʒ��Ϣ
    int type;
    int id;
    int score;

    Goods(int _type, int _id, int _score){
        type=_type; id=_id; score=_score;
    }
    
    bool operator < (const Goods &rhs) const{
        if(score==rhs.score){
            if(type==rhs.type) return id<rhs.id;
            return type<rhs.type;
        }
        return score>rhs.score;
    }
};

struct Del{    //��ɾ������Ʒ��Ϣ
    int type;
    int id;
    
    Del(int _type, int _id){
        type=_type; id=_id;
    }
    
    bool operator < (const Del &rhs) const{
        if(type==rhs.type) return id<rhs.id;
        return type<rhs.type;
    }
};

set<Goods> goods; //���������Ʒ��Ϣ
set<Del> has_del; //���������ɾ������Ʒ��Ϣ

int m, n;
int id, score;
int opnum;
int type;
int K, k[52];

int cnt[52]; //������cnt[i]����i����Ʒ����ѡ��Ŀ�� cnt[51]��ѡ����
vector<int> chosen[52]; //���ÿ��ѡ�е���Ʒ�ı��

int main(){
    scanf("%d%d", &m, &n);
    for(int i=0; i<n; ++i){
        scanf("%d%d", &id, &score);
        for(int j=0; j<m; ++j){
            goods.insert(Goods(j, id, score));
        }
    }
    scanf("%d", &opnum);
    int op; //��������
    for(int i=0; i<opnum; ++i){
        scanf("%d", &op);
        if(op==1){ //��Ӳ���
            scanf("%d%d%d", &type, &id, &score);
            goods.insert(Goods(type, id, score));
        }
        else if(op==2){ //ɾ������
            scanf("%d%d", &type, &id);
            has_del.insert(Del(type, id)); //������Ʒ����ɾ�����У�ʵ�ж���ɾ��
        }
        else{ //��ѯ����
            scanf("%d", &K);
            for(int j=0; j<m; ++j){
                scanf("%d", &k[j]);
            }
            
            memset(cnt, 0, sizeof(cnt));
            for(int j=0; j<m; ++j) chosen[j].clear();
            
            //������ʼ��
            for(set<Goods>::iterator it=goods.begin(); cnt[51]<K && it!=goods.end();){
                //������Ʒδѡ�����鿴����Ʒ�Ƿ���ɾ��
                if(cnt[(*it).type]<k[(*it).type]){
                    if(has_del.find(Del((*it).type, (*it).id))!=has_del.end()){ //������ɾ������
                        goods.erase(it++); //ɾ����Ԫ�أ�����������
                    }
                    //δɾ��
                    else{
                        ++cnt[(*it).type];
                        ++cnt[51];
                        chosen[(*it).type].push_back((*it).id);
                        it++;
                    }
                }
                else it++;
            }
            
            //�����
            for(int j=0; j<m; ++j){
                if(cnt[j]==0) printf("-1\n");
                else{
                    for(vector<int>::iterator it=chosen[j].begin(); cnt[51]<=K && it!=chosen[j].end(); ++it){
                        printf("%d ", *it);
                    }
                    printf("\n");
                }
            }
            
        }
    }
    
    return 0;
}

