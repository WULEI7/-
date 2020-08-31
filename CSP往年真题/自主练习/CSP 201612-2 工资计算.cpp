#include <cstdio>
int main()
{
	int t,c=0,ans=0;
	int before[]={0,3500,5000,8000,12500,38500,58500,83500,100001};
	int after[]={0,3500,4955,7655,11255,30755,44755,61005,100001};
	double rate[]={0,1,0.97,0.9,0.8,0.75,0.7,0.65,0.55};
	scanf("%d",&t);
	while(after[c]<t)
		c++;
	ans=before[c-1]+(t-after[c-1])/rate[c];
	printf("%d\n",ans);
	return 0;
}
