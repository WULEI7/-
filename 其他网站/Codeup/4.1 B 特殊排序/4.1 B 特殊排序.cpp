#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        vector<int> x;
        int y[1010];
        for(int i=0;i<n;i++){
            scanf("%d",&y[i]);
            x.push_back(y[i]);
        }
        if(n==1){
        	printf("%d\n",y[0]);
        	printf("-1\n");
		}
		else{
            sort(x.begin(),x.end());
            printf("%d\n",x[x.size()-1]);
            for(int i=0;i<x.size()-1;i++){
               printf("%d ",x[i]);
            }
            printf("\n");
		}   
    }
    return 0;
    
}
