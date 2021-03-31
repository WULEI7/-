#include <iostream>
#include <cstdio>
#include <string>
#include <vector> 
using namespace std;
int n,a,b,p1,p2,r1,r2,s1,s2,pos[30];
vector<int> vec[30];
void find()
{
	p1=pos[a],p2=pos[b];
	s1=vec[p1].size(),s2=vec[p2].size();
	for(int i=0;i<s1;i++)
	{
		if(vec[p1][i]==a)
		{
			r1=i;
			break;
		}
	}
	for(int i=0;i<s2;i++)
	{
		if(vec[p2][i]==b)
		{
			r2=i;
			break;
		}
	}
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string x,y;
	for(int i=0;i<25;i++)
		vec[i].push_back(i);
	for(int i=0;i<25;i++)
		pos[i]=i;
	cin>>n;
	while(cin>>x)
	{
		if(x=="quit") break;
		cin>>a>>y>>b;
		if(a==b||pos[a]==pos[b]) continue;
		if(x=="move"&&y=="onto")
		{
			find();
			for(int i=r1+1;i<s1;i++)
			{
				vec[vec[p1][i]].push_back(vec[p1][i]);
				pos[vec[p1][i]]=vec[p1][i];
			}//a上方的归位 
			for(int i=r2+1;i<s2;i++)
			{
				vec[vec[p2][i]].push_back(vec[p2][i]);
				pos[vec[p2][i]]=vec[p2][i];
			}//b上方的归位 
			vec[p1].resize(r1);
			vec[p2].resize(r2+1);
			vec[p2].push_back(a);
			pos[a]=p2;
		}
		else if(x=="move"&&y=="over")
		{
			find();
			for(int i=r1+1;i<s1;i++)
			{
				vec[vec[p1][i]].push_back(vec[p1][i]);
				pos[vec[p1][i]]=vec[p1][i];
			}//a上方的归位 
			vec[p1].resize(r1);
			vec[p2].push_back(a);
			pos[a]=p2;
		}
		else if(x=="pile"&&y=="onto")
		{
			find();
			for(int i=r2+1;i<s2;i++)
			{
				vec[vec[p2][i]].push_back(vec[p2][i]);
				pos[vec[p2][i]]=vec[p2][i];
			}//b上方的归位 
			vec[p2].resize(r2+1);
			for(int i=r1;i<s1;i++)
			{
				vec[p2].push_back(vec[p1][i]);
				pos[vec[p1][i]]=p2;
			}
			vec[p1].resize(r1);
		}
		else if(x=="pile"&&y=="over")
		{
			find();
			for(int i=r1;i<s1;i++)
			{
				vec[p2].push_back(vec[p1][i]);
				pos[vec[p1][i]]=p2;
			}
			vec[p1].resize(r1);
		}
	}
	for(int t=0;t<n;t++)
	{
		printf("%d:",t);
		int size=vec[t].size();
		for(int i=0;i<size;i++)
			printf(" %d",vec[t][i]);
		printf("\n");
	}
	return 0;
}
