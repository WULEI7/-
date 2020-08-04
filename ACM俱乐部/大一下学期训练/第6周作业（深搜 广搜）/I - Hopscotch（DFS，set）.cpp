#include <cstdio>
#include <iostream>
#include <set>
using namespace std;
int x[6][6];
set <int> rec;
void dfs(int r,int c,int cur,int num)
{
	if(cur==6)
	{
		rec.insert(num);
		return;
	}
	//if(r<0||r>=5||c<0||c>=5) return;
	if(r-1>=0)
		dfs(r-1,c,cur+1,num*10+x[r-1][c]);
	if(r+1<5)
		dfs(r+1,c,cur+1,num*10+x[r+1][c]);
	if(c-1>=0)
		dfs(r,c-1,cur+1,num*10+x[r][c-1]);
	if(c+1<5)
		dfs(r,c+1,cur+1,num*10+x[r][c+1]);
}
int main()
{
	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++)
			cin>>x[i][j];
	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++)
			dfs(i,j,1,x[i][j]);
	cout<<rec.size()<<endl;
	//for(set<int>::iterator i=rec.begin();i!=rec.end();i++)
	//	cout<<*i<<endl; 
	return 0;
}
