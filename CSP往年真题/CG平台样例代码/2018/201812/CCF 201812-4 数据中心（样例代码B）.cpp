#include<iostream>
#include<algorithm>
using namespace std;
int fa[50003];
struct data
{	
	int u,v,val;
}a[100003];

bool cmp(data a, data b)
{
	if(a.val<b.val)return 1;
	return 0;
}

int find(int x)		
{
	if(fa[x]==x) return x;
	fa[x]=find(fa[x]);  return fa[x];
}

bool unite(int x,int y)		//判断两点是否连通 
{
	x=find(x);y=find(y);
	if(x==y) return false;
	fa[x]=y;return true;
}
  
int main()
{  
	int n,m,q;
	cin>>n>>m>>q;
   	for(int i=1;i<=m;i++)
	cin>>a[i].u>>a[i].v>>a[i].val;
	for(int i=1;i<=n;i++)
	fa[i]=i;
	sort(a+1,a+m+1,cmp);
	int vval=0;
	for(int i=1;i<=m;i++)
	{   
	    if(unite(a[i].u,a[i].v)) vval=a[i].val;		//val非递减排序，所以每次都是max 
		else continue; 
	}
   cout<<vval;
   return 0;
}



