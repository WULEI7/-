#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,a,front[100005],tail,pos[100005];
	memset(front,0,sizeof(front));
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		if(a==-1)
			tail=i;//链表尾结点 
		else
			front[a+1]=i;//前一个结点 
	}
	vector<int> list;//链表 
	while(tail!=0)
	{
		list.push_back(tail);
		tail=front[tail];
	}
	reverse(list.begin(),list.end());//逆序变为正序 
	int size=list.size();
	for(int i=0;i<size;i++)
		pos[list[i]]=i+1;//记录各数值在链表中的位置 
	cout<<pos[1]; 
	for(int i=2;i<=size;i++)
		cout<<" "<<pos[i];
	return 0;
}
