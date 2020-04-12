#include <iostream>
using namespace std;
int main()
{
	int dp[32770]={0};
	dp[0]=1;
	for(int i=1;i<=3;i++)
		for(int j=i;j<32770;j++)
			dp[j]+=dp[j-i];
	int n;
	while(cin>>n)
		cout<<dp[n]<<endl;
	return 0;
}
