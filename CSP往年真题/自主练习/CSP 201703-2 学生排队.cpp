#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int main()
{
	vector<int> s;
	int n,m,p,q;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		s.push_back(i);
	while(m--)
	{
		cin>>p>>q;
		for(int i=0;i<n;i++)
		{
			if(s[i]==p)
			{
				if(q>0)
				{
					s.insert(s.begin()+i+q+1,p);
					s.erase(s.begin()+i);
				}
				else if(q<0)
				{
					s.erase(s.begin()+i);
					s.insert(s.begin()+i+q,p);
				}
				break;
			}
		}
	}
	int size=s.size();
	printf("%d",s[0]);
	for(int i=1;i<size;i++)
		printf(" %d",s[i]);
	printf("\n");
	return 0;
}
