#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string a,b;
	cin>>a>>b;
	int len1=a.length(),len2=b.length();
	int ans=1;
	for(int i=0;i<len1;i++)
	for(int j=1;j<len2;j++)
		if(a[i]==b[j]&&a[i+1]==b[j-1])
			ans*=2;
	cout<<ans<<endl;
	return 0;
}
