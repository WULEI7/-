#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n,a[100];
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	int ans=1,temp=1;
	for(int i=1;i<n;i++)
	{
		if(a[i]==a[i-1])
			temp++;
		else
			temp=1;
		if(temp>ans)
			ans=temp;
	}
	cout<<ans<<endl;
	return 0; 
}
