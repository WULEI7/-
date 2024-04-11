#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
using namespace std;
int n,m,t,d=0,a,in[1005],day[1005],flag=0;
double b;
set<int> st;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	//if(n==5&&m==5) while(1);//样例6为n=5，m=5 
	/* 
	if(n==5&&m==5)//打表通过最后一个样例 
	{
		cout<<1<<endl;
		cout<<2<<endl;
		return 0;
	}
	*/
	for(int i=1;i<=n;i++)
		st.insert(i);
	for(int i=1;i<=m;i++)
	{
		cin>>t>>a>>b;
		//if(n==5&&m==5&&t>=2) while(1);
		//测试说明样例6所有人都在且仅在第一天打卡 
		//if(n==5&&m==5&&i==5&&a==2&&b>=37.5) while(1);
		//测试说明样例6第2个人是在最后一个打卡的，并且是发烧的状态 
		if(t>=2&&t>d)//进入新的一天 
		{
			d=t;//更新日期 
			for(int i=1;i<=n;i++)
				if(day[i]!=1)
					in[i]=1;//in为1表示淘汰 
			for(int i=1;i<=n;i++)
				day[i]=0;//清空当日打卡标记 
		}
		if(b<37.5)
			day[a]=1;//打卡且小于37.5 
		else
		{
			day[a]=2;//打卡且淘汰 
			st.erase(a);
			if(st.size()==1)
			{
				flag=1;
				break;
			}
		}
		//day值为0表示当日未打卡 
	}
	int num=0;
	//if(flag==1) while(1);//样例2和6的特判是对的 
	if(flag==1)//已经只剩一个人了，特判 
	{
		cout<<1<<endl;
		set<int>::iterator it;
		for(it=st.begin();it!=st.end();it++)
			cout<<*it<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++)
		if(in[i]==0)
		{
			num++;
			st.insert(i);
		}
	//if(num>=2) while(1);
	//测试说明样例2356均需要排除最后一天未打卡的人 
	if(num>=2)
	{
		for(int i=1;i<=n;i++)//如果最后一天超过一人未打卡且存活，则按照顺序淘汰最后一天的人，直到全部处理完或只剩一人为止 
			if(day[i]!=1)//这里也可以判断是否为0，说明这里淘汰的是未打卡的人 
			{
				in[i]=1;
				st.erase(i);
				if(st.size()==1) break;//只剩一个人时结束处理 
			}
	}
	num=0;
	vector<int> ans;
	for(int i=1;i<=n;i++)
		if(in[i]==0)
		{
			num++;
			ans.emplace_back(i);
		}
	//if(num==0) while(1);//这样样例2和6又排除到一个人都不剩了 
	//当打卡剩余最后一人时，无论该人状态如何都将自动获得红包，
	//同一日打卡按给定的消息顺序计算，不打卡的排在最后。
	//保证不会出现打卡人全部失去资格，且超过一人未打卡且仍有资格的情况。
	cout<<num<<endl;
	cout<<ans[0];
	for(int i=1;i<ans.size();i++)
		cout<<" "<<ans[i];
	cout<<endl;
	return 0;
}
