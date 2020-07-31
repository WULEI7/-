#include <iostream>
#include <string>
#include <queue>
using namespace std;
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		string s;
		priority_queue <char> a,b;
		cin>>s;
		int len=s.length(),wz,flag=1;
		for(int i=0;i<len;i++)
			if(s[i]=='=')
			{
				wz=i;
				break;
			}
		for(int i=0;i<wz;i++)
			a.push(s[i]);
		for(int i=wz+1;i<len;i++)
			b.push(s[i]);
		int size=a.size();
		while(a.size()&&b.size())
		{
			if(a.top()!=b.top())
			{
				flag=0;
				break;
			}
			a.pop();
			b.pop();
		}
		if(flag)
			cout<<"Y"<<endl;
		else
			cout<<"N"<<endl;
	}
	return 0;
}
