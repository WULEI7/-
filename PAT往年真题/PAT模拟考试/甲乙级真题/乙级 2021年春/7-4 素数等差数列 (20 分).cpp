#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=100005;
bool p[maxn];
int prime[maxn];
int main()
{
	int n,m,size=0;
	cin>>n>>m;
	for(int i=2;i<=m;i++)
	{
		if(!p[i])
		{
			prime[size++]=i;
			for(int j=2*i;j<=m;j+=i)
				p[j]=true;
		}
	}//ËØÊý´ò±í 
	int maxdif=(m-2)/(n-1),begin,d,found=0;
	if(n>1)
		for(int i=maxdif;i>0;i--)
		{
			if(found) break;
			for(int j=size-1;j>=0;j--)
			{
				int cnt=1,next=prime[j]-i;
				while(!p[next]&&next>=2)
				{
					cnt++;
					if(cnt==n) break;
					next-=i;
				}
				if(cnt==n)
				{
					d=i;
					begin=next;
					//begin=prime[j]-d*(n-1);
					found=1;
					break;
				}
			}
		}
	if(found)
	{
		printf("%d",begin);
		for(int i=1;i<n;i++)
			printf(" %d",begin+i*d);
	}
	else
	{
		for(int i=m;i>=2;i--)
		{
			if(!p[i])
			{
				printf("%d",i);
				break;
			}
		}
	}
	return 0;
}
