#include<stdio.h>
#include<algorithm>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int gcd(int a,int b){
	if(b==0){
		return a;
	}
	else{
		return gcd(b,a%b);
	}
}
int main(){
	//freopen("test0.in","r",stdin);
	int n;
	scanf("%d",&n);
	//while(scanf("%d",&n)!=EOF){
	while(n--){
		int m;
		scanf("%d",&m);
		long long num[10000];
		for(int i=0;i<m;i++){
			scanf("%lld",&num[i]);
		}
		if(m==1)
		{
			printf("%lld\n",num[0]);
			continue;
		}
		sort(num,num+m,cmp);
		int y=gcd(num[0],num[1]);
		long long lcm=num[0]/y*num[1];//先算出前两个数字的最小公倍数 
		if(m==2){
			printf("%lld\n",lcm);
			continue;
		}
		for(int i=2;i<m;i++){//多个数字求公倍数就是某个数字前所有数字的公倍数和该数字求公倍数以此类推 
			if(lcm<num[i]){
				y=gcd(num[i],lcm);
			    lcm=num[i]/y*lcm;
			}
			else{
				y=gcd(lcm,num[i]);
				lcm=lcm/y*num[i];
			}		
		}
		printf("%lld\n",lcm);
	}
//}
	return 0;
} 
