#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a[9]={1,2,3,4,5,6,7,8,9};
	do
	{
		if(a[0]+a[1]+a[2]==15&&a[3]+a[4]+a[5]==15&&a[6]+a[7]+a[8]==15&&a[0]+a[3]+a[6]==15&&a[1]+a[4]+a[7]==15&&a[2]+a[5]+a[8]==15&&a[0]+a[4]+a[8]==15&&a[2]+a[4]+a[6]==15)
			break;
	}while(next_permutation(a,a+9));
	for(int i=0;i<9;i++)
	{
		cout<<a[i]<<" ";
		if(i%3==2) cout<<"\n";
	}
	return 0;	
}
