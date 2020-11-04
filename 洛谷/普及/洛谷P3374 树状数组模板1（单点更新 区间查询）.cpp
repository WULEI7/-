#include <iostream> 
#include <cstdio>
using namespace std;
int tree[500005];
int n,m,a[500005];
void update(int i,int val)
{
	while(i<=n)
	{
		tree[i]+=val;
		i+=-i&i;
	}
}//树状数组更新 
long long getsum(int i)
{
	long long sum=0;
	while(i>0)
	{
		sum+=tree[i];
		i-=-i&i;
	}
	return sum;
}//树状数组求和 
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		update(i,a[i]);
	}
	for(int i=1;i<=m;i++)
	{
		int opt,x,y;
		scanf("%d%d%d",&opt,&x,&y);
		if(opt==1)
			update(x,y);
		if(opt==2)
			printf("%d\n",getsum(y)-getsum(x-1));
	}
	return 0;
}
