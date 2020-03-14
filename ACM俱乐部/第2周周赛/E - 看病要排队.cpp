#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
struct patient{
	int b,id;
};//�������ȼ�Ϊb 
bool operator < (patient p1,patient p2)
{
	if(p1.b==p2.b)
		return p1.id>p2.id;
	else
		return p1.b<p2.b;
}//������������������ȼ�һ��ʱidС������ 

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
			}//�����IN��������id��ţ������������Ӧ��ҽ���Ķ��� 
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
			}//�����OUT������Ӧҽ���ĵ�һ�������Ƴ����� 
		}
	}
	return 0;
}
