#include <bits/stdc++.h>
using namespace std;
int main()
{
	int k,i,j,ge,shi,bai,qian,wan,flag=0;
	cin >> k;
	for(i=10000;i<=30000;i++)
	{
		j=i;
		ge=j%10;
		j/=10;
		shi=j%10;
		j/=10;
		bai=j%10;
		j/=10;
		qian=j%10;
		wan=j/10;
		if((wan*100+qian*10+bai)%k==0&&(qian*100+bai*10+shi)%k==0&&(bai*100+shi*10+ge)%k==0)
		{cout << i << "\n";flag=1;}
	}
	if(flag==0) cout << "No";
	return 0;
}
