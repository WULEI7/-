#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n,cnt[5]={0};
	vector<pair<int,int> > pos;
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
		}
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
		}
	}
	for(int i=0;i<5;i++)
		cout<<cnt[i]<<endl;
	return 0;
}
