#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,a[50],i,j,m;
	long long p=1;
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	sort(a,a+n);
	for(i=0;i<n;i++)
	{ 
		p*=(a[i]-i);
		p%=1000000007;//ע�⼰ʱȡģ���������������´��� 
	}
	printf("%lld",p);
	return 0;
}
