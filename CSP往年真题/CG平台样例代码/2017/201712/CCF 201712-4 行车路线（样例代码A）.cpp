#include <iostream>
#include <string.h>
#include <cmath>
#include <vector> 
#include <cstdio>
using namespace std;

typedef long long ll;
const ll INF = 0x7fffffffffffffff;
ll sA[512][512];                //С·���ڽӾ��� 
ll bA[512][512];                //��·���ڽӾ��� 
int isvisited_sr[512];          //С·��������
int isvisited_br[512];          //��·��������
ll n,m;
ll ans;     //��� 

//ƽ������ 
ll Pow2(ll a)
{
    return  a*a;
}


/*  �Ͻ�˹�����㷨
    ����Ѵ�·��С·�ֿ��ж� 
*/ 
ll Dijikstra(ll t)
{   
    vector<ll> sr(sA[t],sA[t]+n);       //��i���С·�ľ������ 
    vector<ll> br(bA[t],bA[t]+n);       //��i����·�ľ������ 
    vector<ll> pre_sr(n,INF);           //��i���С·���ڽӾ���
    for(int i = 0 ; i < n ; i++){
        if(sr[i] < INF){
            pre_sr[i] = sr[i];
            sr[i] *= sr[i];
        } 
    }
    isvisited_br[t] = isvisited_sr[t] = 1;
    while(1){
        ll MinVal = INF,flag = 0,v = -1;
        for(int i = 0 ; i < n ; i++){
            if(!isvisited_br[i] && br[i] < MinVal){//��· 
                flag = 0;
                MinVal = br[v=i];       
            }
            if(!isvisited_sr[i] && sr[i] < MinVal){//С· 
                flag = 1;
                MinVal = sr[v=i];       
            }
        }
        if(v == -1){
            break;
        }
        if(flag == 1){//��· 
            isvisited_sr[v] = 1;
        }else{//С· 
            isvisited_br[v] = 1; 
        }
        for(int i = 0 ; i < n ; i++){
            if(isvisited_sr[i] == 0 && sA[v][i] < INF){//v��i����һ��С· 
                if(flag == 1){//v��ǰ����С· 
                    ll len = sr[v] - Pow2(pre_sr[v]) + Pow2(pre_sr[v]+sA[v][i]);
                    if(sr[i] > len || (sr[i] == len && pre_sr[i] > pre_sr[v]+sA[v][i])){
                        sr[i] = len;
                        pre_sr[i] = pre_sr[v]+sA[v][i];
                    }
                }else{//v��ǰ���Ǵ�· 
                    ll len = br[v]+ Pow2(sA[v][i]);
                    if(sr[i] > len || (sr[i] == len && pre_sr[i] > sA[v][i])){
                        sr[i] = len;
                        pre_sr[i] = sA[v][i]; 
                    }
                }
            }
            if(isvisited_br[i] == 0 && bA[v][i] < INF){//v��i����һ����· 
                if(flag == 1){//v��ǰ����С· 
                    ll len = sr[v] + bA[v][i];
                    br[i] = min(len,br[i]); 
                }else{//v��ǰ���Ǵ�· 
                    ll len = br[v] + bA[v][i];
                    br[i] = min(br[i],len); 
                }
            } 
        }
    }
    return min(sr[n-1],br[n-1]); 
}

int main()
{
    while(cin>>n>>m){
        //��������г�ʼ�� 
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                sA[i][j] = sA[j][i] = INF;
                bA[i][j] = bA[j][i] = INF;
            }
        }

        for(int i = 0 ; i < 512 ; i++){
            isvisited_sr[i] = isvisited_br[i] = 0;
        } 

        //�������룬��ͼ���г�ʼ��
        for(int i = 0 ; i < m ; i++){
            ll t,a,b,c;
            cin>>t>>a>>b>>c;
            a--,b--;
            if(t == 1){
                sA[a][b] = sA[b][a] = min(c,sA[a][b]);
            }else{
                bA[a][b] = bA[b][a] = min(c,bA[a][b]);
            }
        }
        ans = Dijikstra(0);
        printf("%lld\n",ans);
    }

    return 0;
}
