#include <bits/stdc++.h>
using namespace std;
int a[4],b[3],flag=0;
void dfs(int cur,int pla)//cur表示目前b数组已填数字的个数，pla表示前一个填的数在a数组中的位置 
{
	if(cur==3)
	{
		if(b[0]+b[1]>b[2])
			flag=2;
		if(b[0]+b[1]==b[2]&&!flag)
			flag=1;
	}//当b数组中填满3个数字时判断状态 
	else
	{
		for(int i=pla;i<4;i++)
		{
			b[cur]=a[i];
			dfs(cur+1,i+1);
		}
	}//没有满时继续往b数组中填数，满足后填数字比已填数字在a数组中位置靠后 
	return;
}//练习写dfs函数，以解决更具有普遍性的问题（木棍比4根更多时） 

int main()
{
	int i;
	for(i=0;i<4;i++)
		cin>>a[i];//a数组输入各木棍长度 
	sort(a,a+4);//将a数组从小到大排序，以便后续操作 
	dfs(0,0);
	if(flag==0) cout<<"IMPOSSIBLE";
	if(flag==1) cout<<"SEGMENT";
	if(flag==2) cout<<"TRIANGLE";//根据flag状态输出结果 
	return 0;
}
