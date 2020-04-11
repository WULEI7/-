#include<iostream>
#include <algorithm>
using namespace std;
const long long N=1e5;
int main()
{
	long long n,i,j,m;
	long long a[N],b[N],max,c;
	cin>>n>>m;
	for(i=0;i<m;i++)
	{
		cin>>a[i]>>b[i];
	}
	sort(a,a+m);
	sort(b,b+m);
	max=a[0]-1;
	for(j=0;j<m-1;j++)
	{
		if(b[j]<a[j+1]-1)
		{
		c=a[j+1]-b[j]-1;
		if(max<c)
		max=c;}
		else c=0;
	}
	if(max<n-b[j])
	max=n-b[j];
	cout<<max;
	return 0;
}
