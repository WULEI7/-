#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,x,str[200];
	cin>>a>>b>>x;
	for(int i=0;i<a;i++)
		str[i]=0;
	for(int i=a;i<a+b;i++)
		str[i]=1;
	do
	{
		int tot=0;
		for(int i=0;i<a+b-1;i++)
			if(str[i]!=str[i+1])
				tot++;
		if(tot==x) break;
	}while(next_permutation(str,str+a+b));
	for(int i=0;i<a+b;i++)
		cout<<str[i];
	return 0;
}
