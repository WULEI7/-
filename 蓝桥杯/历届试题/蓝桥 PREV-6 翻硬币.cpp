#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main()
{
	string a,b;
	cin>>a>>b;
	int len=a.length(),ans=0,flag=0,temp;
	for(int i=0;i<len;i++)
	{
		
		if(a[i]!=b[i])
		{
			flag++;
			if(flag%2==1)
				temp=i;
			if(flag!=0&&flag%2==0)
				ans+=i-temp;
		}
	}
	cout<<ans<<endl;
	return 0;
}
