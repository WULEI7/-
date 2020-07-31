#include <iostream>
using namespace std;
int main()
{
	int n,cnt[1005]={0};
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int num;
		cin>>num;
		cnt[num]++;
		cout<<cnt[num];
		if(i<n-1)
			cout<<" ";
	}
	return 0;
}
