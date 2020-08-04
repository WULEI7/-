#include<stdio.h> 
int main()
{
	int n,k,a[1005],now,ans,i;
	now=0;ans=0;
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++)scanf("%d",&a[i]);
	for(i=0;i<n;i++){
		now+=a[i];
		if(now>=k){
			ans++;
			now=0;
		}
	}
	if(now>0)ans++;
	printf("%d\n",ans);
	return 0;
}



