#include<stdio.h>
#include<vector>
#include<algorithm>
const int maxn=26*26*26*10;
using namespace std;
vector<int> stu[maxn];//���Ǹ���ά���飬maxn���кţ�ÿ���������ڵ����ﶼ�и�ͬѧѡ��Ŀγ̴���
int stid(char a[]){
   int id=0;
   for(int i=0;i<3;i++){
       id=id*26+(a[i]-'A');
   }
   //���������forѭ��ֱ��д��id=(a[0]-'A')*26*26+(a[1]-'A')*26+(a[2]-'A')
   id=id*10+(a[3]-'0');
   return id;
}
int main(){
    int n,k;//n��ʾ����ѯ��ѧ������k��ʾ�γ���
    int kid,nnum;//kid��ʾ�γ̴��룬nnum��ʾû�ſ�ѧ����
    char name[5];//����
    scanf("%d%d",&n,&k);
    for(int i=0;i<k;i++){
        scanf("%d%d",&kid,&nnum);
        for(int j=0;j<nnum;j++){
            scanf("%s",name);//����ÿ�ſγ��е�ѧ������
            int t=stid(name);//��ѧ��������ӳ�䵽26���Ƶ�����
            stu[t].push_back(kid);//����������ڵĿγ̺Ŷ��ŵ���һ��ĩβ
            
        }
    }
    char stname[5];//��������
    for(int i=0;i<n;i++){
        scanf("%s",stname);//������������ѯ��ѧ��������
        int t=stid(stname);
        sort(stu[t].begin(),stu[t].end());//��ÿλͬѧ�Ŀγ̺����� 
        printf("%s %d",stname,stu[t].size());
        for(int j=0;j<stu[t].size();j++){
            printf(" %d",stu[t][j]);
        }
        printf("\n");
    }
    return 0;
}