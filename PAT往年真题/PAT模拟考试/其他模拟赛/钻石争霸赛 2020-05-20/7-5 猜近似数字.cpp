#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
using namespace std;
int main()
{
	string a,b;
	cin>>a;
	int lena=a.length();
	while(cin>>b)
	{
		if(b=="-1") break;
		int lenb=b.length();
		if(lena!=lenb)
		{
			cout<<"No"<<endl;
			continue;
		}
		int flag=1,time=0;
		for(int i=0;i<lena;i++)
		{
			if(a[i]!=b[i])
			{
				time++;
				if(abs(a[i]-b[i])>1||abs(a[i]-b[i])==1&&time>=2)
				{
					flag=0;
					break;
				}
			}
		}
		if(flag)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}
