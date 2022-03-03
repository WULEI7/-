#include<stdio.h>
#include<algorithm>
using namespace std;
struct moon{
	double st;
	double money;
	double dan;
}moons[1010];
bool cmp(moon a,moon b){
	return a.dan>b.dan;
}
int main(){
	int n;
	double need;
	double ans=0;
	while(scanf("%d %lf",&n,&need)!=EOF){
		for(int i=1;i<=n;i++){
			scanf("%lf",&moons[i].st);
		}
		for(int i=1;i<=n;i++){
			scanf("%lf",&moons[i].money);
		}
		for(int i=1;i<=n;i++){
			moons[i].dan=moons[i].money/moons[i].st;
		}
		sort(moons+1,moons+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(need<=0){
				break;
			}
			if(moons[i].st==need){
				need=need-moons[i].st;
			    ans+=moons[i].money;
			    break;
			}
			else if(moons[i].st<need){
				need=need-moons[i].st;
			    ans+=moons[i].money;
			    moons[i].st=0;
			}
			else{
				//while(1);
				//通过显示“答案错误”还是“运行超时”，判断出这个else分支存在问题 
				
				for(int j=1;j<=moons[i].st;j++){
					ans+=moons[i].dan;
					//moons[i].st-=1;
					//上面这行-1，和for循环的j++重复啦，造成计算错误 
					need=need-1;
					if(need==0){
						break;
					}
				}
				
				//其实上面写复杂了，万一数据范围大会超时
				//因为就是需要的量比当前这种月饼总量少，那么其实可以直接写成 
				//ans+=moons[i].dan*need;
				//break;
			}
			
		}
		printf("%.2f\n",ans);
		
	}
	return 0;
} 
