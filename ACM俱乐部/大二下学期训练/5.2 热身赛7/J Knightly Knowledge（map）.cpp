#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int m,c,x,y;
	map<int,int> monx,mony,chux,chuy;//纪念碑横纵坐标、教堂横纵坐标 
	map<pair<int,int>,int> chup;//教堂位置 
	cin>>m>>c;
	for(int i=0;i<m;i++)
	{
		cin>>x>>y;
		monx[x]++;
		mony[y]++;
	}
	for(int i=0;i<c;i++)
	{
		cin>>x>>y;
		if(monx[x]>1||mony[y]>1) continue;
		chux[x]++;
		chuy[y]++;
		chup[{x,y}]=1;
	}
	map<int,int>::iterator it1,it2;
	int ans=0,posx=0,posy=0;
	for(it1=monx.begin();it1!=monx.end();it1++)
	{
		if(it1->second>1) continue;
		for(it2=mony.begin();it2!=mony.end();it2++)
		{
			if(it2->second>1) continue;
			int temp=chux[it1->first]+chuy[it2->first];
			if(chup[{it1->first,it2->first}]==1)
				temp--;
			if(temp>ans)
			{
				ans=temp;
				posx=it1->first;
				posy=it2->first;
			}
		}
	}
	cout<<posx<<" "<<posy<<endl<<ans<<endl;
	return 0;
}
