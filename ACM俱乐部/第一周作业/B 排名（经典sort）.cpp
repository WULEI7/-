#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <malloc.h> 
using namespace std;

struct node
{
	string ID;
	int solve;
	int no[10];
	int score;
}stu[1000];

bool cmp(node a1,node a2)
{
	if(a1.score>a2.score)
	return true;
	if(a1.score==a2.score)
	return a1.ID<a2.ID;
	return false;
}

int n,m,line,pro[1000];

int main()
{
	std::ios::sync_with_stdio(false);
	while(cin>>n)
	{
		if(n==0) return 0;
		cin>>m>>line;
		for(int i=0;i<m;i++)
			cin>>pro[i];
		for(int i=0;i<n;i++)
		{
			cin>>stu[i].ID;
			cin>>stu[i].solve;
			for(int j=0;j<stu[i].solve;j++)
				cin>>stu[i].no[j];
			stu[i].score=0;
			for(int j=0;j<stu[i].solve;j++)
				stu[i].score+=pro[stu[i].no[j]-1];
		}
		sort(stu,stu+n,cmp);
		int temp=0;
		for(int i=0;i<n;i++)
			if(stu[i].score>=line)
				temp++;
		cout<<temp<<endl;
		for(int i=0;i<temp;i++)
			cout<<stu[i].ID<<" "<<stu[i].score<<endl;
	}
	return 0;
}
