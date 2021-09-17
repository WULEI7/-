#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn=1e6+5;
int heap[maxn],n=0;//最小堆（下标从1开始） 
void deleteTop()//删除堆顶元素 
{
	pop_heap(heap+1,heap+1+n,greater<int>());
	n--;
}
void insert(int x)//插入元素 
{
	heap[++n]=x;
	push_heap(heap+1,heap+1+n,greater<int>());
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t,a,b;
	cin>>t;
	while(t--)
	{
		cin>>a;
		if(a==1)
		{
			cin>>b;
			insert(b);
		}
		if(a==2)
			cout<<heap[1]<<endl;
		if(a==3)
			deleteTop();
	}
	return 0;
}
