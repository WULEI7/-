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
				//ͨ����ʾ���𰸴��󡱻��ǡ����г�ʱ�����жϳ����else��֧�������� 
				
				for(int j=1;j<=moons[i].st;j++){
					ans+=moons[i].dan;
					//moons[i].st-=1;
					//��������-1����forѭ����j++�ظ�������ɼ������ 
					need=need-1;
					if(need==0){
						break;
					}
				}
				
				//��ʵ����д�����ˣ���һ���ݷ�Χ��ᳬʱ
				//��Ϊ������Ҫ�����ȵ�ǰ�����±������٣���ô��ʵ����ֱ��д�� 
				//ans+=moons[i].dan*need;
				//break;
			}
			
		}
		printf("%.2f\n",ans);
		
	}
	return 0;
} 
