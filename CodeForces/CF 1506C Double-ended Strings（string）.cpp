#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		string a,b;
		cin>>a>>b;
		int maxlen=0;
		int lena=a.length();
		int lenb=b.length();
		for(int i=0;i<lena;i++)
		for(int j=i;j<lena;j++)
		{
			int find=b.find(a.substr(i,j-i+1));
			if(find!=-1)
				if(j-i+1>maxlen)
					maxlen=j-i+1;
		}
		cout<<lena+lenb-2*maxlen<<endl;
	}
	return 0;
}
