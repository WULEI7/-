#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int maxn=100005;
bool p[maxn];
int v[maxn];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,size=0;
	cin>>n>>m;
	for(int i=2;i<=m;i++)
	{
		if(!p[i])
		{
			v[size++]=i;
			//vec.emplace_back(i);
			for(int j=2*i;j<=m;j+=i)
				p[j]=1;
		}
	}//ËØÊý´ò±í 
	//cout<<size<<endl;
	int dif=(m-2)/(n-1),begin,d,found=0;
	if(n>1)
	{
		for(int i=dif;i>0;i--)
		{
			if(found) break;
			for(int j=size-1;j>0;j--)
			{
				int cnt=1,next=v[j]-i;
				while(p[next]==0&&next>=2)
				{
					cnt++;
					next-=i;
				}
				if(cnt>=n)
				{
					d=i;
					begin=v[j]-d*(n-1);
					found=1;
					break;
				}
			}
		}
	}
	if(found)
	{
		cout<<begin;
		for(int i=1;i<n;i++)
			cout<<" "<<begin+i*d;
		cout<<endl;
	}
	else
	{
		for(int i=m;i>=2;i--)
			if(!p[i])
			{
				cout<<i<<endl;
				break;
			}
	}
	return 0;
}
