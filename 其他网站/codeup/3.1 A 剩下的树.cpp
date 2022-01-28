#include<stdio.h>
#include <algorithm>
using namespace std;
int main(){
    int l,m,begin,end,tree[10005];
    while(scanf("%d%d",&l,&m)!=EOF)
	{
		if(l==0&&m==0) break;//输入0 0时结束 
		for(int i=0;i<=l;i++)
			tree[i]=1;//注意每组数据要将tree数组初始化  
		//fill(tree,tree+l+1,1);或者用fill函数，加上头文件<algorithm>和using namespace std; 
		//如果是统一赋值成0或者-1，可以用memset函数，头文件是<cstring> 
    	int ans=0;
        for(int i=0;i<m;i++){
            scanf("%d%d",&begin,&end);
            for(int j=begin;j<=end;j++){
                tree[j]=0; 
            }
        }
        for(int i=0;i<=l;i++){
            if(tree[i]==1){
                ans++;
            }
        }
        printf("%d\n",ans);
    }
    
    return 0;
}
