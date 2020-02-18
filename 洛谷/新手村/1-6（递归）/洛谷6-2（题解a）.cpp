#include<iostream>
#include<cstdio>
#include<cmath>  //sqrt()的函数库
using namespace std;
int a[10001];  //记录所选的数
int n,k,sum,total;  //total为总方案数
inline void print()  //打印函数（依照个人习惯）
{
    printf("%d",total);
}
inline bool prime(int x)  //素数判断
{
    for(register int i=2;i<=sqrt(x);i++)
        if(x%i==0)
            return false;
    return true;
}
inline void dfs(int step,int sum,int cnt)
{
    if(step==n+1||cnt==k)  //如果已经进行到了n+1次，或者是已经选了k个数
    {
        if(prime(sum) && cnt==k)  //如果sum为一个素数且已经选了k个数
            total++;  //总方案书+1
        return;  //返回
    }
    dfs(step+1,sum+a[step],cnt+1);  //继续搜索，选择下一个数
    dfs(step+1,sum,cnt);  //继续枚举不选择下一个数的情况
    return;
}
int main()
{
    scanf("%d %d",&n,&k);
    for(register int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    dfs(1,0,0);  //从第个数开始搜
    print();  //最后打印结果
    return 0;
}
