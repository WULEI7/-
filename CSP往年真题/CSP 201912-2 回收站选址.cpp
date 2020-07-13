#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n,cnt[5]={0};
	vector<pair<int,int> > pos;//保存所有垃圾点的坐标 
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		pos.push_back({x,y});
	}
	for(int i=0;i<n;i++)
	{
		int x=pos[i].first,y=pos[i].second,flag=0;
		for(int j=0;j<n;j++)
		{
			if(pos[j].first==x-1&&pos[j].second==y)
				flag++;
			if(pos[j].first==x+1&&pos[j].second==y)
				flag++;
			if(pos[j].first==x&&pos[j].second==y-1)
				flag++;
			if(pos[j].first==x&&pos[j].second==y+1)
				flag++;
		}//判断是否符合上下左右四处都有垃圾 
		if(flag==4)
		{
			int temp=0;
			for(int j=0;j<n;j++)
			{
				if(pos[j].first==x-1&&pos[j].second==y-1)
					temp++;
				if(pos[j].first==x-1&&pos[j].second==y+1)
					temp++;
				if(pos[j].first==x+1&&pos[j].second==y-1)
					temp++;
				if(pos[j].first==x+1&&pos[j].second==y+1)
					temp++;
			}
			cnt[temp]++;
		}//判断四个对角位置有几处有垃圾，并用cnt数组对不同得分的回收站选址计数 
	}
	for(int i=0;i<5;i++)
		cout<<cnt[i]<<endl;
	return 0;
}
