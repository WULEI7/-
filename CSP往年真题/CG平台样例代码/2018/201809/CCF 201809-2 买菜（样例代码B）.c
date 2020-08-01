#include<stdio.h>
#include<math.h>
struct time{
	int beg,end;
}h[2005],w[2005];
int main(){
	int n,i;
	long long sum=0,s,t;
	int k1=0,k2=0;	
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d",&h[i].beg,&h[i].end);
	}
	for(i=0;i<n;i++){
		scanf("%d%d",&w[i].beg,&w[i].end);
	}

	while(k1<n&&k2<n){
		
		if(h[k1].end<w[k2].beg){
			k1++;
		}
		else if(h[k1].beg>w[k2].end){
			k2++;
		}
		else{
			if(h[k1].beg>w[k2].beg)s=h[k1].beg;
			else s=w[k2].beg;
			if(h[k1].end<w[k2].end)t=h[k1].end;
			else t=w[k2].end;
			
			sum+=t-s;
			if(h[k1].end<w[k2].end)k1++;
			else k2++;
		}
		
	}
	printf("%lld\n",sum);
	return 0;
}
			



