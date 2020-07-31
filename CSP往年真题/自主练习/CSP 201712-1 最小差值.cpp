#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n,num[1005];
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>num[i];
	sort(num,num+n);
	int ans=10000;
	for(int i=1;i<n;i++)
		if(num[i]-num[i-1]<ans)
			ans=num[i]-num[i-1];
	cout<<ans<<endl;
	return 0;
}
