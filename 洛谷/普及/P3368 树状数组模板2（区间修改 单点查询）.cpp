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
		scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
	{
		int opt,x,y,z;
		scanf("%d",&opt);
		if(opt==1)
		{
			scanf("%d%d%d",&x,&y,&z);
			update(x,z);
			update(y+1,-z);
		}
		if(opt==2)
		{
			scanf("%d",&x);
			printf("%d\n",a[x]+getsum(x));
		}
	}
	return 0;
}
