#include<stdio.h>
#include <algorithm>
using namespace std;
int main(){
    int l,m,begin,end,tree[10005];
    while(scanf("%d%d",&l,&m)!=EOF)
	{
		if(l==0&&m==0) break;//����0 0ʱ���� 
		for(int i=0;i<=l;i++)
			tree[i]=1;//ע��ÿ������Ҫ��tree�����ʼ��  
		//fill(tree,tree+l+1,1);������fill����������ͷ�ļ�<algorithm>��using namespace std; 
		//�����ͳһ��ֵ��0����-1��������memset������ͷ�ļ���<cstring> 
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
