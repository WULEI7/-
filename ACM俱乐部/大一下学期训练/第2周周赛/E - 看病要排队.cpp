#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
struct patient{
	int b,id;
};//病人优先级为b 
bool operator < (patient p1,patient p2)
{
	if(p1.b==p2.b)
		return p1.id>p2.id;
	else
		return p1.b<p2.b;
}//重载运算符，病人优先级一样时id小的优先 

int main()
{
	ios::sync_with_stdio(false);
	int n;
	while(cin>>n)
	{
		int doc,k=1;
		priority_queue <patient> doctor[5];
		while(n--)
		{
			string s;
			cin>>s>>doc;
			if(s=="IN")
			{
				patient pat;
				pat.id=k++;
				cin>>pat.b;
				doctor[doc].push(pat);
			}//如果是IN，给病人id编号，将病人排入对应的医生的队列 
			if(s=="OUT")
			{
				if(doctor[doc].empty())
					cout<<"EMPTY"<<endl;
				else
				{
					patient pat;
					pat=doctor[doc].top();
					doctor[doc].pop();
					cout<<pat.id<<endl;
				}
			}//如果是OUT，将对应医生的第一个病人移出队列 
		}
	}
	return 0;
}
