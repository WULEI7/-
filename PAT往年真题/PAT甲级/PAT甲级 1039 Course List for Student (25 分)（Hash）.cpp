#include<stdio.h>
#include<vector>
#include<algorithm>
const int maxn=26*26*26*10;
using namespace std;
vector<int> stu[maxn];//这是个二维数组，maxn是行号，每个名字所在的行里都有该同学选择的课程代码
int stid(char a[]){
   int id=0;
   for(int i=0;i<3;i++){
       id=id*26+(a[i]-'A');
   }
   //或者这里的for循环直接写成id=(a[0]-'A')*26*26+(a[1]-'A')*26+(a[2]-'A')
   id=id*10+(a[3]-'0');
   return id;
}
int main(){
    int n,k;//n表示来查询的学生数，k表示课程数
    int kid,nnum;//kid表示课程代码，nnum表示没门课学生数
    char name[5];//名字
    scanf("%d%d",&n,&k);
    for(int i=0;i<k;i++){
        scanf("%d%d",&kid,&nnum);
        for(int j=0;j<nnum;j++){
            scanf("%s",name);//输入每门课程中的学生姓名
            int t=stid(name);//将学生的姓名映射到26进制的数字
            stu[t].push_back(kid);//这个名字所在的课程号都放到这一行末尾
            
        }
    }
    char stname[5];//所有名字
    for(int i=0;i<n;i++){
        scanf("%s",stname);//输入所有来查询的学生的名字
        int t=stid(stname);
        sort(stu[t].begin(),stu[t].end());//给每位同学的课程号排序 
        printf("%s %d",stname,stu[t].size());
        for(int j=0;j<stu[t].size();j++){
            printf(" %d",stu[t][j]);
        }
        printf("\n");
    }
    return 0;
}