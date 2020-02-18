#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,i,j,ans=0,num[1000]={6},bang[10]={6,2,5,5,4,5,6,3,7,6};
	for(i=1;i<1000;i++)
	{
		j=i;
		while(j)
		{
			num[i]+=bang[j%10];
			j/=10;
		}
	}
	cin >> n;
	for(i=0;i<1000;i++)
		for(j=0;j<1000-i;j++)
			if(num[i]+num[j]+num[i+j]==n-4) ans++;
	cout << ans;
	return 0;
}
